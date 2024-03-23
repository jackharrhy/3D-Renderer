#pragma once
#include "render_context.h"

namespace ngfx{
struct MemoryAllocation;
struct ImageOffset{
    int32_t x;
    int32_t y;
    int32_t z;
};
struct ImageExtent{
    uint32_t width;
    uint32_t height;
    uint32_t depth;
};
struct ImageRegion{
    ImageOffset offset;
    ImageExtent extent;
};
struct ImageInfo{
    ImageExtent extent;
};
class Image {
public:
    Image();
    Image(ImageInfo info);
    ~Image();
    
    void Initialize(ImageInfo info);
    void Terminate();
    
    void WriteDescriptor(VkDescriptorSet descriptor_set, uint32_t binding, uint32_t index);

public:
    void CreateImage();
    void CreateView();
    
    void GetMemoryRequirements(VkMemoryRequirements* memory_requirements);
    void BindMemory(VkDeviceMemory vk_memory, VkDeviceSize offset);
    
    ImageExtent extent_;
    VmaAllocation vma_allocation;
    VkImage image_;
    VkImageView view_;
};
}
