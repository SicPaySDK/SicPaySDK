//
//  SicPay.h
//  SicPaySDk
//
//  Created by Leo on 2018/4/26.
//  Copyright © 2018年 Scipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,SicPayEnvironment) {
    SicPayEnvironmentTest = 0,     //测试环境
    SicPayEnvironmentProduct = 1,  //生产环境
};

typedef NS_ENUM(NSInteger,SicPayResultStatus) {
    SicPayResultStatusUnpay   = 0,        //未支付
    SicPayResultStatusSuccess = 1,        //支付成功
    SicPayResultStatusFail    = 2,        //支付失败
    SicPayResultStatusCancel  = 4,        //支付取消
};

typedef NS_ENUM(NSInteger,SicResultBlockScene) {
    SicResultBlockSceneImmediately   = 0,        //获取到支付结果的立即回调
    SicResultBlockSceneSDKPageDismiss = 1,       //SDK页面退出的回调
};

typedef void (^SicPayCompletion)(NSDictionary *result, SicPayResultStatus payStatus, SicResultBlockScene blockScene);


typedef void (^ResultSuccessBlock)(NSDictionary *result);

typedef void(^ResultFailureBlock)(id responseData, NSString* code);

@interface SicPay : NSObject

/**
 *  SDK                  配置
 *  @param  environment  开发环境       0:测试 1:生产
 *  @parm   Abroad       境内外         YES:境外 NO:境内
 */
+ (void)setEnvironment:(SicPayEnvironment)environment
                Abroad:(BOOL)abroad;
//INAPP不同渠道跳转支付配置的
+ (void)setUPOPScheme:(NSString *)scheme;
+ (void)setWeChatScheme:(NSString *)scheme WxAppid:(NSString *)WxAppid universalLink:(NSString *)universalLink;


/// 跳转微信小程序并进行支付
/// @param userName 小程序原始ID
/// @param path 跳转的页面路径，传@""为默认跳转首页
/// @param miniProgramType 小程序的版本类型（0:正式，1:开发，2:体验）
/// @param payresultCompletionBlock SDK检测到支付结果回调 (blockFrom代表什么场景下的block回调)
+ (void)createPaymentWeChatMiniProgramWithUserName:(NSString *)userName
                                    Path:(NSString *)path
                         MiniProgramType:(int)miniProgramType payResultCompletion:(SicPayCompletion)payresultCompletionBlock;



+ (void)setTngWalletScheme:(NSString *)scheme;
+ (void)setCCFHCWaletScheme:(NSString *)scheme;
+ (void)setAliPayScheme:(NSString *)scheme;
//Apple Pay(如果不支持，不需要设置)
+ (void)setApplePayMerchantID:(NSString *)appleMerchantId;

+ (void)setUserId:(NSString *)userId;




/**
 *  处理app跳转回调
 *  @param  url  待处理url
 *  @param  sourceApplication  待处理sourceApplication
 */
+ (BOOL)handleURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication;



/*! @brief 处理通过Universal Link启动App时传递的数据
*
* 需要在 application:continueUserActivity:restorationHandler:中调用。
* @param userActivity 启动第三方应用时系统API传递过来的userActivity
* @return 成功返回YES，失败返回NO。
*/
+ (BOOL)handleOpenUniversalLink:(NSUserActivity *) userActivity;


/**
 *  支付调用接口
 *
 *  @param merchant_no              商户ID
 *  @param child_no                 子商户号
 *  @param terminal_no              终端ID
 *  @param payParams                预订单参数信息 NSDictionary对象  (键值主要值为token_id)
                                                                  (内购需要传入iap_product_id)
 *  @param show                     是否使用SDK支付成功页
 *  @param dismissAniamation        SDK是否需要退出动画
 *  @param viewController           调起的控制器
 *  @param singleBankCode           如果只想直接调起某一种支付，传该种支付的bankcode（请参照SDK文档）
 *  @param payresultCompletionBlock SDK检测到支付结果回调 (blockFrom代表什么场景下的block回调)
 */
+ (void)createPaymentWithMerchantNo:(NSString *)merchant_no
                    childMerchantNo:(NSString *)child_no
                         terminalNo:(NSString *)terminal_no
                          payParams:(NSDictionary *)payParams
                     showResultPage:(BOOL)show
               SDKDismissAniamation:(BOOL)dismissAniamation
                     viewController:(UIViewController *)viewController
                  singlePaymentType:(NSString *)singleBankCode
                payResultCompletion:(SicPayCompletion)payresultCompletionBlock;
/**
 *  版本号
 *
 *  @return         SicPay SDK 报文版本号
 */
+ (NSString *)version;

/**
 *  版本号
 *
 *  @return         SicPay SDK 当前版本号
 */
+ (NSString *)SDKCurrent_Version;


/**
 *  版本环境
 *
 *  @return         SicPay SDK 开发环境
 */
+ (SicPayEnvironment)SDKEnviroment;

/**
 *  SDK是否境外
 *
 *  @return         SicPay SDK 是否境外版本
 */
+ (BOOL)isAbroad;

/**
 *  设置 Debug 模式
 *
 *  @param enabled    是否启用
 */
+ (void)setDebugMode:(BOOL)enabled;

/**
 *  设置 导航栏颜色 (支持UIColor和16进制颜色字符串)
 *  @param  navColor  SicPay 导航栏背景色
 *  @param  tintColor  SicPay 导航栏文字按钮色
 */
+ (void)setNavgationBarColor:(id)navColor
                   tintColor:(id)tintColor;

/**
 内部调试用，请勿使用
 */
+ (NSString *)getStrWithKey1:(NSString *)key1
                        key2:(NSInteger)key2
                        key3:(NSString *)key3;



@end
