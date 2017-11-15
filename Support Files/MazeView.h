//
//  MazeView.h
//  maze
//
//  Created by 翟元浩 on 2017/11/13.
//  Copyright © 2017年 翟元浩. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "Maze.hpp"

@interface MazeView : NSView

@property (nonatomic) Maze myMaze;
@property (nonatomic) MyPoint startPoint;
@property (nonatomic) MyPoint endPoint;
@property (nonatomic) Stack<MyPoint> pointStack;

- (void)setMaze:(void **)maze height:(int)height width:(int)width startPoint:(MyPoint)startPoint endPoint:(MyPoint)endPoint;
- (void)getPath;

@end
