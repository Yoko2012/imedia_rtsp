#ifndef __VIDEO_INPUT_H__
#define __VIDEO_INPUT_H__

#include <hi_defines.h>
#include <hi_comm_vi.h>
#include <mpi_vi.h>

#include <glib.h>
#include <glib-object.h>
#include "stream_descriptor.h"

#define IPCAM_VIDEO_INPUT_TYPE (ipcam_video_input_get_type())
#define IPCAM_VIDEO_INPUT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), IPCAM_VIDEO_INPUT_TYPE, IpcamVideoInput))
#define IPCAM_VIDEO_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), IPCAM_VIDEO_INPUT_TYPE, IpcamVideoInputClass))
#define IPCAM_IS_VIDEO_INPUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), IPCAM_VIDEO_INPUT_TYPE))
#define IPCAM_IS_VIDEO_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), IPCAM_VIDEO_INPUT_TYPE))
#define IPCAM_VIDEO_INPUT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), IPCAM_VIDEO_INPUT_TYPE, IpcamVideoInputClass))

typedef struct _IpcamVideoInput IpcamVideoInput;
typedef struct _IpcamVideoInputClass IpcamVideoInputClass;

struct _IpcamVideoInput
{
    GObject parent;
};

struct _IpcamVideoInputClass
{
    GObjectClass parent_class;
};

GType ipcam_video_input_get_type(void);
gint32 ipcam_video_input_start(IpcamVideoInput *self, StreamDescriptor desc[]);
gint32 ipcam_video_input_stop(IpcamVideoInput *self);
gint32 ipcam_video_input_query(IpcamVideoInput *self, VI_CHN_STAT_S *stat);
void ipcam_video_input_param_change(IpcamVideoInput *self, StreamDescriptor desc[]);
void ipcam_video_input_set_image_parameter(IpcamVideoInput *self, IpcamMediaImageAttr *attr);

#endif /* __VIDEO_INPUT_H__ */
