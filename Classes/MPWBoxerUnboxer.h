//
//  MPWBoxerUnboxer.h
//  ObjectiveSmalltalk
//
//  Created by Marcel Weiher on 3/6/14.
//
//

#import <Foundation/Foundation.h>


typedef id (^BoxBlock)(void *buffer, int maxBytes);
typedef id (^BoxVarargBlock)(va_list arglist);
typedef void (^UnboxBlock)(id anObject, void *buffer, int maxBytes);


@interface MPWBoxerUnboxer : NSObject

-(void)unboxObject:anObject intoBuffer:(void*)buffer maxBytes:(int)maxBytes;
-boxedObjectForBuffer:(void*)buffer maxBytes:(int)maxBytes;
-boxedObjectForVararg:(va_list)ap;

+nspointBoxer;
+nsrectBoxer;

+boxer:(BoxBlock)newBoxer unboxer:(UnboxBlock)newUnboxer;


+(void)setBoxer:(MPWBoxerUnboxer*)aBoxer forTypeString:(NSString*)typeString;
+(MPWBoxerUnboxer*)converterForType:(const char*)typeString;
+(MPWBoxerUnboxer*)converterForTypeString:(NSString*)typeString;

@end
