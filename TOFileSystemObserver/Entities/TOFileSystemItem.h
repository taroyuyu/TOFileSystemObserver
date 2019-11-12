//
//  TOFileSystemItem.h
//
//  Copyright 2019 Timothy Oliver. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to
//  deal in the Software without restriction, including without limitation the
//  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
//  sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
//  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import <UIKit/UIKit.h>

// The different types of items stored in the file system
typedef NS_ENUM(NSInteger, TOFileSystemItemType) {
    TOFileSystemItemTypeFile, // A standard file
    TOFileSystemItemTypeDirectory // A folder
};

@class TOFileSystemObserver;

NS_ASSUME_NONNULL_BEGIN

/**
 An object that represents either a file
 or folder on disk.
 */
@interface TOFileSystemItem : NSObject

/** The absolute URL path to this item. */
@property (nonatomic, readonly) NSURL *fileURL;

/** The type of the item (either a file or folder) */
@property (nonatomic, assign) TOFileSystemItemType type;

/** The unique UUID that was assigned to the file by this library. */
@property (nonatomic, copy) NSString *uuid;

/** The name on disk of the item. */
@property (nonatomic, copy) NSString *name;

/** The size (in bytes) of this item. (0 for directories). */
@property (nonatomic, assign) long long size;

/** The creation date of the item. */
@property (nonatomic, strong) NSDate *creationDate;

/** The last modification date of the item. */
@property (nonatomic, strong) NSDate *modificationDate;

/** Whether the item is still being copied into the app container. */
@property (nonatomic, assign) BOOL isCopying;

/** Create a new, unmanaged instance to represent the file at the given URL. */
- (instancetype)initWithItemAtFileURL:(NSURL *)fileURL;

/** Refresh the properties of the item against the file at the given URL. */
- (BOOL)refreshFromItemAtURL:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
