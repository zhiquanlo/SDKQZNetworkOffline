

Pod::Spec.new do |s|
  s.name         = "SDKQZNetworkOffline"
  s.version      = "1.0.6"
  s.summary      = "趣智校园蓝牙交互SDK网络版"
  s.description  = <<-DESC
			趣智校园蓝牙交互SDK网络版1.0.6版本
                   DESC

  s.homepage     = "https://github.com/zhiquanlo/SDKQZNetworkOffline.git"
  s.license      = "MIT"
  s.author             = { "李志权" => "373765482@qq.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/zhiquanlo/SDKQZNetworkOffline.git", :tag => "#{s.version}" }

  s.source_files  = "SDKQZNetworkOffline/*.{h}"
  s.ios.deployment_target = "8.0"
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  s.vendored_libraries = 'SDKQZNetworkOffline/*.a'
  s.xcconfig = {'VALID_ARCHS[sdk=*]' => '' }
end
