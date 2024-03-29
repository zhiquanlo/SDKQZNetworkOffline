

Pod::Spec.new do |s|
  s.name         = "SDKQZNetworkOffline"
  s.version      = "1.2.0"
  s.summary      = "趣智校园蓝牙交互SDK网络版"
  s.description  = <<-DESC
			优化了SDK
                   DESC

  s.homepage     = "https://github.com/zhiquanlo/SDKQZNetworkOffline.git"
  s.license      = "MIT"
  s.author             = { "李志权" => "373765482@qq.com" }
  s.platform     = :ios, "9.0"
  s.source       = { :git => "https://github.com/zhiquanlo/SDKQZNetworkOffline.git", :tag => "#{s.version}" }
  s.ios.deployment_target = "9.0"
  s.pod_target_xcconfig = {
	'OTHER_LDFLAGS' => '-ObjC'
 }
  s.requires_arc = false
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  s.vendored_frameworks = 'SDKQZNetworkOffline1.2.0/*.framework'
end
