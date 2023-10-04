
Pod::Spec.new do |s|
  s.name             = 'cococlientsdk-swift'
  s.version          = '0.0.1'
  s.summary          = 'A library to wrap libcocomediasdk.'

  s.description      = <<-DESC
  Swift wrappers around libcococlientsdk.so,
  this wrapper can be used rapid develop of COCO applications on iOS platform.
  DESC

  s.homepage         = 'https://github.com/danyliak1/cococlientsdk-swift'
  s.license          = { :type => 'Copyright', :text => <<-LICENSE
                  	 Copyright 2018
                 	 Permission is granted to...
                	 LICENSE
               	       }
  s.authors          = {  'rohan-elear' => 'rohansahay@elear.solutions',
                          'shrinivas-elear' => 'shrinivasgutte@elear.solutions',
                          'danyliak1' => 'vladdanulyak@gmail.com' }
  s.source           = {  :git => 'https://github.com/elear-solutions/cococlientsdk-swift-framework.git',
                          :tag => "#{s.version}" }

  s.swift_version = '5'
  s.platform = :ios
  s.ios.deployment_target = '11.0'
  s.preserve_paths = "IOTClientSDK.xcframework/*"

 s.xcconfig = {
        'FRAMEWORK_SEARCH_PATH[sdk=iphoneos*]' => '$(inherited) "$(PODS_ROOT)/IOTClientSDK"',
        'OTHERCFLAGS[sdk=iphoneos*]' => '$(inherited) -iframework "$(PODS_ROOT)/IOTClientSDK"',
        'OTHER_LDFLAGS[sdk=iphoneos*]' => '$(inherited) -framework IOTClientSDK'
    }
end