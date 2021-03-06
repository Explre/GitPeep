//
//  TYNetworkEngine.h
//  GitPeep
//
//  Created by tiany on 2018/2/28.
//  Copyright © 2018年 tianyao. All rights reserved.
//

#import <MKNetworkKit/MKNetworkKit.h>

typedef void(^CompletionDictionaryBlock)(NSDictionary *responseDictionary);

typedef void(^CompletionArrayBlock)(NSArray *responseArray);

typedef void(^ErrorBlock)(NSError *error);

@interface TYNetworkEngine : MKNetworkEngine

+ (instancetype)sharedInstance;

/// SearchUsers
- (MKNetworkOperation *)searchUsersWithPage:(NSUInteger)page
                                          q:(NSString *)q
                                       sort:(NSString *)sort
                                   location:(NSString *)location
                                   language:(NSString *)language
                           completionHandle:(CompletionDictionaryBlock)completionBlock
                                errorHandle:(ErrorBlock)errorBlock;

/// UserDetail
- (MKNetworkOperation *)userDetailWithUserName:(NSString *)userName
                              completionHandle:(CompletionDictionaryBlock)completionBlock
                                   errorHandle:(ErrorBlock)errorBlock;

/// UserRepositories
- (MKNetworkOperation *)userRepositoriesWithUserName:(NSString *)userName
                                                page:(NSUInteger)page
                                    completionHandle:(CompletionArrayBlock)completionBlock
                                         errorHandle:(ErrorBlock)errorBlock;

/// UserFollowing
- (MKNetworkOperation *)userFollowingWithUserName:(NSString *)userName
                                             page:(NSUInteger)page
                                 completionHandle:(CompletionArrayBlock)completionBlock
                                      errorHandle:(ErrorBlock)errorBlock;

/// UserFollowers
- (MKNetworkOperation *)userFollowersWithUserName:(NSString *)userName
                                             page:(NSUInteger)page
                                 completionHandle:(CompletionArrayBlock)completionBlock
                                      errorHandle:(ErrorBlock)errorBlock;

/// SearchRepositories
- (MKNetworkOperation *)searchRepositoriesWithPage:(NSUInteger)page
                                                 q:(NSString *)q
                                              sort:(NSString *)sort
                                  completionHandle:(CompletionDictionaryBlock)completionBlock
                                       errorHandle:(ErrorBlock)errorBlock;

/// RepositoryDetail
- (MKNetworkOperation *)repositoryDetailWithUserName:(NSString *)userName
                                      repositoryName:(NSString *)repositoryName
                                    completionHandle:(CompletionDictionaryBlock)completionBlock
                                         errorHandle:(ErrorBlock)errorBlock;

/// RepositoryCategory
- (MKNetworkOperation *)reposDetailCategoryWithUserName:(NSString *)userName
                                                   page:(NSUInteger)page
                                         repositoryName:(NSString *)repositoryName
                                               category:(NSString *)category
                                       completionHandle:(CompletionArrayBlock)completionBlock
                                            errorHandle:(ErrorBlock)errorBlock;

@end
