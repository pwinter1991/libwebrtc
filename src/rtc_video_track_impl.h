#ifndef LIB_WEBRTC_VIDEO_TRACK_IMPL_HXX
#define LIB_WEBRTC_VIDEO_TRACK_IMPL_HXX

#include "api/media_stream_interface.h"
#include "modules/video_capture/video_capture_factory.h"
#include "rtc_types.h"
#include "rtc_video_sink_adapter.h"
#include "rtc_video_source_impl.h"
#include "rtc_video_track.h"

namespace libwebrtc {

typedef std::vector<rtc::scoped_refptr<RTCVideoSource>> VideoSourceVector;

class VideoTrackImpl : public RTCVideoTrack {
 public:
  VideoTrackImpl(rtc::scoped_refptr<webrtc::VideoTrackInterface> rtc_track);

  virtual ~VideoTrackImpl();

  virtual void AddRenderer(
      RTCVideoRenderer<scoped_refptr<RTCVideoFrame>>* renderer) override;

  virtual void RemoveRenderer(
      RTCVideoRenderer<scoped_refptr<RTCVideoFrame>>* renderer) override;

  virtual const char* kind() const override { return kind_; }

  virtual const char* id() const override { return id_; }

  virtual bool enabled() const override { return rtc_track_->enabled(); }

  virtual bool set_enabled(bool enable) override {
    return rtc_track_->set_enabled(enable);
  }

  virtual rtc::scoped_refptr<webrtc::VideoTrackInterface> rtc_track() {
    return rtc_track_;
  }

 private:
  rtc::scoped_refptr<webrtc::VideoTrackInterface> rtc_track_;
  scoped_refptr<RTCVideoSourceImpl> video_source_;
  scoped_refptr<VideoSinkAdapter> video_sink_;
  char id_[kMaxStringLength], kind_[kShortStringLength];
};

}  // namespace libwebrtc

#endif  // LIB_WEBRTC_VIDEO_TRACK_IMPL_HXX
