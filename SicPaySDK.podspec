Pod::Spec.new do |s|
  s.name         = "SicPaySDK" # 项目名称
  s.version      = "1.1.9"        # 版本号 与 你仓库的 标签号 对应
  s.license      = "MIT"          # 开源证书
  s.summary      = "this is a payment SDK devlopmented by SicPaySDK." # 项目简介

  s.homepage     = "https://github.com/SicPaySDK/SicPaySDK.git" # 你的主页
  s.source       = { :git => "https://github.com/SicPaySDK/SicPaySDK.git", :tag => "#{s.version}" }#你的仓库地址，不能用SSH地址
  # s.source_files = "Classes/*.{h,m}" # 
  s.requires_arc = true # 是否启用ARC
  s.platform     = :ios, "9.0" #平台及支持的最低版本

  s.pod_target_xcconfig = { "VALID_ARCHS" => "x86_64 armv7 arm64" }
  
  # User  
  s.author             = { "SicPay" => "tech@sicpay.com" } # 作者信息
  s.social_media_url   = "https://github.com/SicPaySDK" # 个人主页


#特别重要，这里必须配置，否则上传成功，找不到.framework,只有头文件
   s.vendored_frameworks = "Classes/SicPaySDk.framework"

   s.resources = "Classes/SicSDKResources.bundle"

   s.dependency "OpenSSL-Universal"

   s.libraries = "z","c++"



end
