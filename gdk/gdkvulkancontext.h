/* GDK - The GIMP Drawing Kit
 *
 * gdkvulkancontext.h:  specific Vulkan wrappers
 *
 * Copyright © 2016  Benjamin Otte
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GDK_VULKAN_CONTEXT__
#define __GDK_VULKAN_CONTEXT__

#if !defined (__GDK_H_INSIDE__) && !defined (GDK_COMPILATION)
#error "Only <gdk/gdk.h> can be included directly."
#endif

#include <gdk/gdkversionmacros.h>
#include <gdk/gdktypes.h>

#ifdef GDK_WINDOWING_VULKAN
#include <vulkan/vulkan.h>
#endif

G_BEGIN_DECLS

#define GDK_TYPE_VULKAN_CONTEXT             (gdk_vulkan_context_get_type ())
#define GDK_VULKAN_CONTEXT(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GDK_TYPE_VULKAN_CONTEXT, GdkVulkanContext))
#define GDK_IS_VULKAN_CONTEXT(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GDK_TYPE_VULKAN_CONTEXT))

#define GDK_VULKAN_ERROR                    (gdk_vulkan_error_quark ())

GDK_AVAILABLE_IN_3_90
GQuark gdk_vulkan_error_quark (void);

GDK_AVAILABLE_IN_3_90
GType gdk_vulkan_context_get_type (void) G_GNUC_CONST;

#ifdef GDK_WINDOWING_VULKAN

GDK_AVAILABLE_IN_3_90
VkInstance              gdk_vulkan_context_get_instance             (GdkVulkanContext  *context);
GDK_AVAILABLE_IN_3_90
VkPhysicalDevice        gdk_vulkan_context_get_physical_device      (GdkVulkanContext  *context);
GDK_AVAILABLE_IN_3_90
VkDevice                gdk_vulkan_context_get_device               (GdkVulkanContext  *context);
GDK_AVAILABLE_IN_3_90
VkQueue                 gdk_vulkan_context_get_queue                (GdkVulkanContext  *context);

#endif /* GDK_WINDOWING_VULKAN */

G_END_DECLS

#endif /* __GDK_VULKAN_CONTEXT__ */