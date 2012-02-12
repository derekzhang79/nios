//
//  Nios_http_parser.h
//  nios
//
//  Created by Sebastian Waisbrot on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "http_parser.h"

@class Nios;
@interface Nios_http_parser : NSObject {
	Nios* nios;
	http_parser* parser;
	NSMutableArray* fields;
	NSMutableArray* values;

	NSString* url;
}

@property (readonly) http_parser* parser;

- (int) on_message_begin;
- (int) on_headers_complete;
- (int) on_message_complete;
- (int) on_url:(const char*) at length:(size_t)length;
- (int) on_header_field:(const char*) at length:(size_t)length;
- (int) on_header_value:(const char*) at length:(size_t)length;
- (int) on_body:(const char*) at length:(size_t)length;

@end
