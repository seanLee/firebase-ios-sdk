/*
 * Copyright 2020 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "GoogleDataTransport/GDTCORLibrary/Public/GoogleDataTransport/GDTCORUploader.h"

NS_ASSUME_NONNULL_BEGIN

#if !NDEBUG
/** A notification fired when uploading is complete, detailing the number of events uploaded. */
extern NSNotificationName const GDTCCTUploadCompleteNotification;
#endif  // #if !NDEBUG

// TODO: Refine API and API docs

/** Class capable of uploading events to the CCT backend. */
@interface GDTCCTUploadOperation : NSOperation

- (instancetype)initWithTarget:(GDTCORTarget)target conditions:(GDTCORUploadConditions)conditions;

/** YES if a batch upload attempt was performed. NO otherwise. If NO for the finished operation,
 * then  there were no events suitable for upload. */
@property(nonatomic, readonly) BOOL uploadAttempted;

/** The queue on which all CCT uploading will occur. */
@property(nonatomic, readonly) dispatch_queue_t uploaderQueue;

/** The URL session that will attempt upload. */
@property(nonatomic, readonly) NSURLSession *uploaderSession;

/** The current upload task. */
@property(nullable, nonatomic, readonly) NSURLSessionUploadTask *currentTask;

/** The next upload time for the CCT target. */
@property(nullable, nonatomic) GDTCORClock *CCTNextUploadTime;

/** The next upload time for the FLL target. */
@property(nullable, nonatomic) GDTCORClock *FLLNextUploadTime;

#if !NDEBUG
/** An upload URL used across all targets. For testing only. */
@property(nullable, nonatomic) NSURL *testServerURL;

#endif  // !NDEBUG

@end

NS_ASSUME_NONNULL_END