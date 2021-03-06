#pragma once
#include "tga_core.h"
#include "tga_input.hpp"
#include <any>
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <initializer_list>
#include <string>
#include <system_error>
#include <tuple>
#include <memory>
#include <vector>
#include <cassert>
#include <variant>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iostream>
#include <fstream>
#include <functional>


namespace tga
{
    //Type Safe Handles
    struct Shader{
        Shader():handle(TGA_NULL_HANDLE){}
        Shader(std::nullptr_t):handle(TGA_NULL_HANDLE){}
        Shader(TgaShader tgaShader):handle(tgaShader){}
        Shader& operator=(TgaShader tgaShader)
        {
            handle = tgaShader;
            return *this;
        }
        operator TgaShader() const
        {
            return handle;
        }
        explicit operator bool() const
        {
            return handle != TGA_NULL_HANDLE;
        }
        bool operator !() const
        {
            return handle == TGA_NULL_HANDLE;
        }
        private:
        TgaShader handle;
    };

    struct Buffer{
        Buffer():handle(TGA_NULL_HANDLE){}
        Buffer(std::nullptr_t):handle(TGA_NULL_HANDLE){}
        Buffer(TgaBuffer tgaBuffer):handle(tgaBuffer){}
        Buffer& operator=(TgaBuffer tgaBuffer)
        {
            handle = tgaBuffer;
            return *this;
        }
        operator TgaBuffer() const
        {
            return handle;
        }
        explicit operator bool() const
        {
            return handle != TGA_NULL_HANDLE;
        }
        bool operator !() const
        {
            return handle == TGA_NULL_HANDLE;
        }
        private:
        TgaBuffer handle;
    };
    

    struct Texture{
        Texture():handle(TGA_NULL_HANDLE){}
        Texture(std::nullptr_t):handle(TGA_NULL_HANDLE){}
        Texture(TgaTexture tgaTexture):handle(tgaTexture){}
        Texture& operator=(TgaTexture tgaTexture)
        {
            handle = tgaTexture;
            return *this;
        }
        operator TgaTexture() const
        {
            return handle;
        }
        explicit operator bool() const
        {
            return handle != TGA_NULL_HANDLE;
        }
        bool operator !() const
        {
            return handle == TGA_NULL_HANDLE;
        }
        private:
        TgaTexture handle;
    };

    struct Window{
        Window():handle(TGA_NULL_HANDLE){}
        Window(std::nullptr_t):handle(TGA_NULL_HANDLE){}
        Window(TgaWindow tgaWindow):handle(tgaWindow){}
        Window& operator=(TgaWindow tgaWindow)
        {
            handle = tgaWindow;
            return *this;
        }
        operator TgaWindow() const
        {
            return handle;
        }
        explicit operator bool() const
        {
            return handle != TGA_NULL_HANDLE;
        }
        bool operator !() const
        {
            return handle == TGA_NULL_HANDLE;
        }
        private:
        TgaWindow handle;
    };

    struct InputSet{
        InputSet():handle(TGA_NULL_HANDLE){}
        InputSet(std::nullptr_t):handle(TGA_NULL_HANDLE){}
        InputSet(TgaInputSet tgaInputSet):handle(tgaInputSet){}
        InputSet& operator=(TgaInputSet tgaInputSet)
        {
            handle = tgaInputSet;
            return *this;
        }
        operator TgaInputSet() const
        {
            return handle;
        }
        explicit operator bool() const
        {
            return handle != TGA_NULL_HANDLE;
        }
        bool operator !() const
        {
            return handle == TGA_NULL_HANDLE;
        }
        private:
        TgaInputSet handle;
    };

  

    struct RenderPass{
        RenderPass():handle(TGA_NULL_HANDLE){}
        RenderPass(std::nullptr_t):handle(TGA_NULL_HANDLE){}
        RenderPass(TgaRenderPass tgaRenderPass):handle(tgaRenderPass){}
        RenderPass& operator=(TgaRenderPass tgaRenderPass)
        {
            handle = tgaRenderPass;
            return *this;
        }
        operator TgaRenderPass() const
        {
            return handle;
        }
        explicit operator bool() const
        {
            return handle != TGA_NULL_HANDLE;
        }
        bool operator !() const
        {
            return handle == TGA_NULL_HANDLE;
        }
        private:
        TgaRenderPass handle;
    };

    struct CommandBuffer{
        CommandBuffer():handle(TGA_NULL_HANDLE){}
        CommandBuffer(std::nullptr_t):handle(TGA_NULL_HANDLE){}
        CommandBuffer(TgaCommandBuffer tgaCommandBuffer):handle(tgaCommandBuffer){}
        CommandBuffer& operator=(TgaCommandBuffer tgaCommandBuffer)
        {    
            handle = tgaCommandBuffer;
            return *this;
        }
        operator TgaCommandBuffer() const
        {
            return handle;
        }
        explicit operator bool() const
        {
            return handle != TGA_NULL_HANDLE;
        }
        bool operator !() const
        {
            return handle == TGA_NULL_HANDLE;
        }
        private:
        TgaCommandBuffer handle;
    };

    //enum classes
    enum class ShaderType{
        undefined,
        vertex,
        fragment,
        compute
    };

    enum class ShaderInput{
        uniformBuffer,
        sampler2D
    };

    enum class BufferUsage: uint32_t{
        undefined = 0x0,
        uniform = 0x1,
        vertex = 0x2,
        index = 0x4
    };
    inline BufferUsage operator|(BufferUsage a, BufferUsage b)
    {
        return static_cast<BufferUsage>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
    }
    inline bool operator&(BufferUsage a, BufferUsage b)
    {
        return bool(static_cast<uint32_t>(a) & static_cast<uint32_t>(b));
    }

    enum class SamplerMode{
        nearest,
        linear
    };

    enum class RepeatMode{
        clampBorder,
        clampEdge,
        repeate,
        repeateMirrow
    };

    enum class PresentMode{
        immediate,
        vsync,
    };


    enum class Format{
        undefined,
        r8_uint,
        r8_sint,
        r8_srgb,
        r8_unorm,
        r8_snorm,
        r8g8_uint,
        r8g8_sint,
        r8g8_srgb,
        r8g8_unorm,
        r8g8_snorm,
        r8g8b8_uint,
        r8g8b8_sint,
        r8g8b8_srgb,
        r8g8b8_unorm,
        r8g8b8_snorm,
        r8g8b8a8_uint,
        r8g8b8a8_sint,
        r8g8b8a8_srgb,
        r8g8b8a8_unorm,
        r8g8b8a8_snorm,
        r32_uint,
        r32_sint,
        r32_sfloat,
        r32g32_uint,
        r32g32_sint,
        r32g32_sfloat,
        r32g32b32_uint,
        r32g32b32_sint,
        r32g32b32_sfloat,
        r32g32b32a32_uint,
        r32g32b32a32_sint,
        r32g32b32a32_sfloat
    };

    enum class CompareOperation{
        ignore,
        equal,
        greater,
        greaterEqual,
        less,
        lessEqual
    };

    enum class BlendFactor{
        zero,
        one,
        srcAlpha,
        oneMinusSrcAlpha,
        dstAlpha,
        oneMinusDstAlpha
    };

    enum class ClearOperation{
        none,
        color,
        depth,
        all
    };

    enum class BindingType{
        uniformBuffer,
        sampler2D
    };

    enum class CullMode{
        none,
        front,
        back,
        all
    };

    enum class FrontFace{
        clockwise,
        counterclockwise
    };

    enum class PolygonMode{
        solid,
        wireframe
    };

    

    //Special Input Structs
    struct VertexAttribute{
        size_t offset;
        Format format;
        VertexAttribute(size_t _offset = 0, Format _format = Format::undefined):
            offset(_offset),format(_format){}
    };

    struct VertexLayout{
        size_t vertexSize;
        std::vector<VertexAttribute> vertexAttributes;
        VertexLayout(size_t _vertexSize = 0, std::vector<VertexAttribute> const &_vertexAttributes = std::vector<VertexAttribute>()):
            vertexSize(_vertexSize),vertexAttributes(_vertexAttributes){}

    };

    struct RasterizerConfig{
        CompareOperation depthCompareOp;
        bool blendEnabled;
        BlendFactor srcBlend;
        BlendFactor dstBlend;
        FrontFace frontFace;
        CullMode cullMode;
        PolygonMode polygonMode;
        RasterizerConfig(CompareOperation _depthCompareOp = CompareOperation::ignore,bool _blendEnabled = false,
                        BlendFactor _srcBlend = BlendFactor::srcAlpha,BlendFactor _dstBlend = BlendFactor::oneMinusSrcAlpha,
                        FrontFace _frontFace = FrontFace::clockwise,CullMode _cullMode = CullMode::none, PolygonMode _polygonMode = PolygonMode::solid):
            depthCompareOp(_depthCompareOp),blendEnabled(_blendEnabled),srcBlend(_srcBlend),dstBlend(_dstBlend),
            frontFace(_frontFace),cullMode(_cullMode),polygonMode(_polygonMode){}
    };

    struct BindingLayout{
        BindingType type;
        uint32_t count;
        BindingLayout(BindingType _type, uint32_t _count = 1):type(_type),count(_count){}
    };

    struct SetLayout{
        std::vector<BindingLayout> bindingLayouts;
        SetLayout(const std::vector<BindingLayout> &_bindingLayouts = {}):bindingLayouts(_bindingLayouts){}
    };

    struct InputLayout{
        std::vector<SetLayout> setLayouts;
        InputLayout(const std::vector<SetLayout> &_setLayouts = {}):setLayouts(_setLayouts){}
    };

    struct Binding{
        std::variant<Buffer, Texture> resource;
        uint32_t slot;
        uint32_t arrayElement;
        Binding(std::variant<Buffer, Texture> _resource = Buffer(), uint32_t _slot = 0,uint32_t _arrayElement = 0):
            resource(_resource),slot(_slot),arrayElement(_arrayElement){}
    };


    //CreationInfos
    struct ShaderInfo{
        ShaderType type;
        uint8_t const *src;
        size_t srcSize;
        ShaderInfo(ShaderType _type=ShaderType::undefined, uint8_t const *_src=nullptr, size_t _srcSize=0):
            type(_type),src(_src),srcSize(_srcSize){}
        ShaderInfo(ShaderType _type=ShaderType::undefined, std::vector<uint8_t> const &_src = std::vector<uint8_t>()):
            type(_type),src(_src.data()),srcSize(_src.size()){}
    };
    struct BufferInfo{
        BufferUsage usage;
        uint8_t const *data;
        size_t dataSize;
        BufferInfo(BufferUsage _usage = BufferUsage::undefined, uint8_t const *_data=nullptr, size_t _dataSize=0):
            usage(_usage),data(_data),dataSize(_dataSize){}
        BufferInfo(BufferUsage _usage = BufferUsage::undefined,std::vector<uint8_t> const &_data = std::vector<uint8_t>()):
            usage(_usage),data(_data.data()),dataSize(_data.size()){}
    };
    struct TextureInfo{
        uint32_t width;
        uint32_t height;
        uint8_t const *data;
        size_t dataSize;
        Format format;
        SamplerMode samplerMode;
        RepeatMode repeatMode;
        TextureInfo(uint32_t _width = 0, uint32_t _height = 0, uint8_t const *_data = nullptr, size_t _dataSize = 0, Format _format = Format::undefined,
                    SamplerMode _samplerMode = SamplerMode::nearest, RepeatMode _repeateMode = RepeatMode::clampBorder):
            width(_width), height(_height), data(_data), dataSize(_dataSize), format(_format), samplerMode(_samplerMode),repeatMode(_repeateMode){}
        TextureInfo(uint32_t _width = 0, uint32_t _height = 0, std::vector<uint8_t> const &_data = std::vector<uint8_t>(), Format _format = Format::undefined,
                SamplerMode _samplerMode = SamplerMode::nearest, RepeatMode _repeateMode = RepeatMode::clampBorder):
        width(_width), height(_height), data(_data.data()), dataSize(_data.size()), format(_format), samplerMode(_samplerMode),repeatMode(_repeateMode){}
    };
    struct WindowInfo{
        uint32_t width;
        uint32_t height;
        PresentMode presentMode;
        uint32_t framebufferCount;
        WindowInfo(uint32_t _width = 0, uint32_t _height = 0, PresentMode _presentMode = PresentMode::immediate,uint32_t _framebufferCount=0):
            width(_width), height(_height), presentMode(_presentMode),framebufferCount(_framebufferCount){}
    };

    struct InputSetInfo{
        RenderPass targetRenderPass;
        uint32_t setIndex;
        std::vector<Binding> bindings;
        InputSetInfo(RenderPass _targetRenderPass,uint32_t _setIndex, std::vector<Binding> const &_bindings):
            targetRenderPass(_targetRenderPass),setIndex(_setIndex),bindings(_bindings){}
    };

    struct RenderPassInfo{
        std::vector<Shader> shaderStages;
        std::variant<Texture, Window> renderTarget;
        ClearOperation clearOperations;
        VertexLayout vertexLayout;
        RasterizerConfig rasterizerConfig;
        InputLayout inputLayout;
        RenderPassInfo(std::vector<Shader> const &_shaderStages = std::vector<Shader>(), 
                    std::variant<Texture, Window> _renderTarget = Texture(), VertexLayout _vertexLayout = VertexLayout(),
                    ClearOperation _clearOperations = ClearOperation::none,
                    RasterizerConfig _rasterizerConfig = RasterizerConfig(), InputLayout _inputLayout = InputLayout()):
            shaderStages(_shaderStages),renderTarget(_renderTarget),clearOperations(_clearOperations),
            vertexLayout(_vertexLayout),rasterizerConfig(_rasterizerConfig),inputLayout(_inputLayout){}
    };
    struct CommandBufferInfo{
        CommandBufferInfo(){}
    };

    //What you interact with
    class Interface{
        public:
        //Resource Creation
        virtual ~Interface() = default;
        virtual Shader createShader(const ShaderInfo &shaderInfo) = 0;
        virtual Buffer createBuffer(const BufferInfo &bufferInfo) = 0;
        virtual Texture createTexture(const TextureInfo &textureInfo) = 0;
        virtual Window createWindow(const WindowInfo &windowInfo) = 0;
        virtual InputSet createInputSet(const InputSetInfo &inputSetInfo) = 0;
        virtual RenderPass createRenderPass(const RenderPassInfo &renderPassInfo) = 0;

        //Commands
        virtual void beginCommandBuffer(const CommandBufferInfo &commandBufferInfo) = 0;
        virtual void setRenderPass(RenderPass renderPass, uint32_t framebufferIndex) = 0;
        virtual void bindVertexBuffer(Buffer buffer) = 0;
        virtual void bindIndexBuffer(Buffer buffer) = 0;
        virtual void bindInputSet(InputSet inputSet) = 0;
        virtual void draw(uint32_t vertexCount, uint32_t firstVertex) = 0;
        virtual void drawIndexed(uint32_t indexCount, uint32_t firstIndex, uint32_t vertexOffset) = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
        virtual CommandBuffer endCommandBuffer() = 0;
        virtual void execute(CommandBuffer commandBuffer) = 0;

        virtual void updateBuffer(Buffer buffer, uint8_t const *data, size_t dataSize, uint32_t offset) = 0;

        //Window functions;
        virtual uint32_t backbufferCount(Window window) = 0;
        virtual uint32_t nextFrame(Window window) = 0;
        virtual void present(Window window) = 0;
        virtual void setWindowTitel(Window window, const std::string &title)=0;

        virtual bool windowShouldClose(Window window) = 0;
        virtual bool keyDown(Window window, Key key) = 0;
        virtual std::pair<int, int> mousePosition(Window window) = 0;


        //Freedom
        virtual void free(Shader shader) = 0;
        virtual void free(Buffer buffer) = 0;
        virtual void free(Texture texture) = 0;
        virtual void free(Window window) = 0;
        virtual void free(InputSet inputSet) = 0;
        virtual void free(RenderPass renderPass) = 0;
        virtual void free(CommandBuffer commandBuffer) = 0;
    };
}
