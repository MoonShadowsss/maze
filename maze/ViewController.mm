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

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
    int maze[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 0},
    };
    MyPoint startPoint = MyPoint(0, 0);
    MyPoint endPoint = MyPoint(6, 6);
    [_mazeView setMaze:(void **)maze height:7 width:7 startPoint:startPoint endPoint:endPoint];
    _mazeView.myMaze.getPathByBFS();
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


@end
