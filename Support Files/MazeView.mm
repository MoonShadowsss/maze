//
//  MazeView.m
//  maze
//
//  Created by 翟元浩 on 2017/11/13.
//  Copyright © 2017年 翟元浩. All rights reserved.
//

#import "MazeView.h"

@interface MazeView()

@property (nonatomic) NSMutableArray *maze;
@property (nonatomic) int height;
@property (nonatomic) int width;

@end

@implementation MazeView

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    CGContextRef context = [[NSGraphicsContext currentContext] CGContext];
    CGContextSetRGBFillColor(context, 1, 0, 0, 1);
    if (_maze && _height && _width) {
        for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++) {
                if ([[NSString stringWithFormat:@"%@", [[_maze objectAtIndex:i] objectAtIndex:j]] isEqual: @"1"]) {
                    CGContextSetRGBFillColor(context, 0, 1, 0, 1);
                    CGContextFillRect(context, [self getCGRectOfPoint:j y:i]);
                }
                CGContextSetRGBStrokeColor(context, 1, 0, 0, 1);
                CGContextStrokeRect(context, [self getCGRectOfPoint:j y:i]);
            }
        }
        CGContextSetRGBFillColor(context, 0, 0, 1, 0.7);
        if (!_pointStack.isEmpty()) {
            Stack<MyPoint> tem = _pointStack;
            while (!tem.isEmpty()) {
                MyPoint point = tem.getTop();
                CGContextFillRect(context, [self getCGRectOfPoint:point.Column() y:point.Row()]);
                tem.pop();
            }
        }
    }
}

- (CGRect)getCGRectOfPoint:(int)x y:(int)y {
    if (x <= _width && y <= _height) {
        CGRect rect = CGRectMake(self.frame.size.width / _width * x, self.frame.size.height / _height * y, self.frame.size.width / _width, self.frame.size.height / _height);
        return rect;
    } else {
        return CGRectMake(0, 0, 0, 0);
    }
}

- (void)setMaze:(void **)maze height:(int)height width:(int)width startPoint:(MyPoint)startPoint endPoint:(MyPoint)endPoint {
    _height = height;
    _width = width;
    _myMaze = Maze(maze, height, width, startPoint, endPoint);
    _maze = [NSMutableArray arrayWithCapacity:height * width];
    for (int i = 0 ; i < height; i++) {
        NSMutableArray *array = [NSMutableArray arrayWithCapacity:width];
        for (int j = 0; j < width; j++) {
            [array addObject:[NSNumber numberWithInt:*((int *)maze + i * width + j)]];
        }
        [_maze addObject:array];
    }
    [self setNeedsDisplay:true];
}

- (void)getPath {
    if (_maze && _height && _width) {
        if (!_pointStack.isEmpty()) {
            _pointStack = *new Stack<MyPoint>;
        } else {
            _pointStack = _myMaze.getBFSStack();
         }
    }
    [self setNeedsDisplay:true];
}

- (BOOL)isFlipped {
    return true;
}

- (void)mouseDown:(NSEvent *)event {
    NSLog(@"%f, %f", event.locationInWindow.x, event.locationInWindow.y);
    NSInteger x = (int)event.locationInWindow.x / ((int)self.frame.size.width / _myMaze.Length());
    NSInteger y = _myMaze.Height() - ((int)event.locationInWindow.y - 20)/ (((int)self.frame.size.height) / _myMaze.Height()) - 1;
    NSLog(@"%d, %d", x, y);
    if (x < _myMaze.Length() && y <_myMaze.Height()) {
        if ([[[_maze objectAtIndex:y] objectAtIndex:x] isEqual:[NSNumber numberWithInt:1]]) {
            [[_maze objectAtIndex:y] setObject:[NSNumber numberWithInt:0] atIndex:x];
        } else {
            [[_maze objectAtIndex:y] setObject:[NSNumber numberWithInt:1] atIndex:x];
        }
        _myMaze.reverseAt(x, y);
    }
    [self setNeedsDisplay:YES];
}

@end
