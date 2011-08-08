//
//  DelaunayTriangle.h
//  DelaunayTest
//
//  Created by Mike Rotondo on 7/17/11.
//  Copyright 2011 Stanford. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DelaunayPoint;
@class DelaunayEdge;
@class DelaunayTriangulation;

@interface DelaunayTriangle : NSObject {
    CFArrayRef nonretainingEdges;
    DelaunayPoint *startPoint;
    UIColor *color;
}

@property (nonatomic, assign) NSArray *edges;
@property (nonatomic, assign) DelaunayPoint *startPoint;
@property (nonatomic, retain) UIColor *color;
@property (nonatomic, readonly) NSArray *points;

+ (DelaunayTriangle *) triangleWithEdges:(NSArray *)edges andStartPoint:(DelaunayPoint *)startPoint;
- (BOOL)containsPoint:(DelaunayPoint *)point;
- (CGPoint)circumcenter;
- (BOOL)inFrameTriangleOfTriangulation:(DelaunayTriangulation *)triangulation;
- (void)remove;
- (void)drawInContext:(CGContextRef)ctx;
- (NSSet *)neighbors;
- (DelaunayPoint *)pointNotInEdge:(DelaunayEdge *)edge;
- (DelaunayEdge *)edgeStartingWithPoint:(DelaunayPoint *)point;
- (DelaunayEdge *)edgeEndingWithPoint:(DelaunayPoint *)point;
- (DelaunayPoint *)startPointOfEdge:(DelaunayEdge *)edgeInQuestion;
- (DelaunayPoint *)endPointOfEdge:(DelaunayEdge *)edgeInQuestion;

- (BOOL)isEqual:(id)object;
- (NSUInteger)hash;

@end
