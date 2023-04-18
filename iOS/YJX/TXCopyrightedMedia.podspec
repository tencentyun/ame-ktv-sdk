#
# Be sure to run `pod lib lint TXCopyrightedMedia.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'TXCopyrightedMedia'
  s.version          = '3.5.0'
  s.summary          = 'ame sdk for iOS'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/tencentyun/ame-ktv-sdk.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zhiruiou' => 'zhiruiou@tencent.com' }
  s.source           = { :http => 'https://mediacloud-76607.gzc.vod.tencent-cloud.com/TXCopyrightedMedia/Release/3.5.0/YJX_SDK.zip' }

  s.ios.deployment_target = '9.0'
  s.static_framework = true
  s.vendored_frameworks = 'YJX_SDK/TXCopyrightedMedia.framework'
  s.public_header_files = 'YJX_SDK/TXCopyrightedMedia.framework/Headers/*.h'
  s.preserve_paths = 'YJX_SDK/TXCopyrightedMedia.framework'
  s.source_files = 'YJX_SDK/TXCopyrightedMedia.framework/Headers/*.h'
  s.frameworks = ['CoreTelephony']
  
  s.libraries = "c++"
  
end
