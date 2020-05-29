

Pod::Spec.new do |s|
  s.name         = "SDKQZNetworkOffline"
  s.version      = "1.0.2"
  s.summary      = "趣智校园蓝牙交互SDK网络版"
  s.description  = <<-DESC
			趣智校园蓝牙交互SDK网络版1.0.1版本
                   DESC

  s.homepage     = "https://github.com/zhiquanlo/SDKQZNetworkOffline.git"
  s.license      = "MIT"
  s.author             = { "李志权" => "373765482@qq.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/zhiquanlo/SDKQZNetworkOffline.git", :tag => "#{s.version}" }

  s.source_files  = 'SDKQZNetworkOffline'
  s.exclude_files = "Classes/Exclude"

  s.ios.deployment_target = "8.0"
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  s.vendored_libraries = "Frameworks/SDKQZNetworkOffline.a"
  s.xcconfig = {'VALID_ARCHS' => arm64, arm64e, armv7, armv7s}
end
