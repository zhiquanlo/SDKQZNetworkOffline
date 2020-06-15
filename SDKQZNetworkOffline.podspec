

Pod::Spec.new do |s|
  s.name         = "SDKQZNetworkOffline"
  s.version      = "1.1.0"
  s.summary      = "趣智校园蓝牙交互SDK网络版"
  s.description  = <<-DESC
			趣智校园蓝牙交互SDK网络版1.1.0版本,增加了热泵设置，MAC地址处理
                   DESC

  s.homepage     = "https://github.com/zhiquanlo/SDKQZNetworkOffline.git"
  s.license      = "MIT"
  s.author             = { "李志权" => "373765482@qq.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/zhiquanlo/SDKQZNetworkOffline.git", :tag => "#{s.version}" }
  s.source_files  = "SDKQZNetworkOffline1.1.0/*.{h}"
  s.ios.deployment_target = "8.0"
  s.pod_target_xcconfig = {'OTHER_LDFLAGS' => '-ObjC' }
  s.requires_arc = false
  s.vendored_frameworks = 'SDKQZNetworkOffline1.1.0/*.framework'
end
