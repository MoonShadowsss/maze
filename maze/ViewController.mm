//
//  ViewController.m
//  maze
//
//  Created by 翟元浩 on 2017/11/13.
//  Copyright © 2017年 翟元浩. All rights reserved.
//

#import "ViewController.h"

@interface ViewController()

@property (weak) IBOutlet MazeView *mazeView;

@end

@implementation ViewController

int maze[9][9] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 1, 1, 0, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 1},
    {0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 0, 0, 0, 0},
};
MyPoint startPoint = MyPoint(0, 0);
MyPoint endPoint = MyPoint(8, 8);

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
    [_mazeView setMaze:(void **)maze height:9 width:9 startPoint:startPoint endPoint:endPoint];
}

- (IBAction)pathButton:(NSButton *)sender {
    [_mazeView getPath];
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


@end
