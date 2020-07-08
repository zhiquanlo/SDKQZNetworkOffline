

Pod::Spec.new do |s|
  s.name         = "SDKQZNetworkOffline"
  s.version      = "1.1.4"
  s.summary      = "趣智校园蓝牙交互SDK网络版"
  s.description  = <<-DESC
			趣智校园蓝牙交互SDK网络版1.1.4版本,增加了热泵设置，MAC地址处理 模拟器真机整合
                   DESC

  s.homepage     = "https://github.com/zhiquanlo/SDKQZNetworkOffline.git"
  s.license      = "MIT"
  s.author             = { "李志权" => "373765482@qq.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/zhiquanlo/SDKQZNetworkOffline.git", :tag => "#{s.version}" }
  s.ios.deployment_target = "8.0"
  s.pod_target_xcconfig = {
	'OTHER_LDFLAGS' => '-ObjC'
 }
  s.requires_arc = false
  s.vendored_frameworks = 'SDKQZNetworkOffline1.1.4/*.framework'
end
