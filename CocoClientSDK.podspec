#
# Be sure to run `pod lib lint CocoClientSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'CocoClientSDK'
  s.version          = '0.2.46'
  s.summary          = 'A library to wrap libcococlientsdk.'

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  Swift wrappers around libcococlientsdk.so,
  this wrapper can be used rapid develop of COCO applications on iOS platform.
  DESC

  s.homepage         = 'https://github.com/ashishbajaj99/cococlientsdk-swift'
  s.license          = { :type => 'Commercial', :file => 'LICENSE' }
  s.authors          = {  'rohan-elear' => 'rohansahay@elear.solutions',
                          'shrinivas-elear' => 'shrinivasgutte@elear.solutions' }
  s.source           = {  :git => 'https://github.com/rohan-elear/cococlientsdk-swift-framework.git',
                          :tag => "v#{s.version.to_s}" }

  s.swift_version = '4.2'
  s.platform = [:ios, :macos]
  s.ios.deployment_target = '11.0'
  s.osx.deployment_target = '10.13'
  s.vendored_frameworks = 'CocoClientSDK.xcframework'
end
