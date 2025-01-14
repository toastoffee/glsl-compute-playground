/**
  ******************************************************************************
  * @file           : renderer.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/10/9
  ******************************************************************************
  */



#ifndef METAL_PLAYGROUND_RENDERER_HPP
#define METAL_PLAYGROUND_RENDERER_HPP

#include <Metal/Metal.hpp>
#include <AppKit/AppKit.hpp>
#include <MetalKit/MetalKit.hpp>

#include <simd/simd.h>

struct FrameData
{
    float angle;
};

class Renderer {
private:
    MTL::Device* _device;
    MTL::CommandQueue* _commandQueue;
    MTL::RenderPipelineState* _PSO;
    MTL::Buffer* _vertexPositionsBuffer;
    MTL::Buffer* _vertexColorsBuffer;
    MTL::Library* _shaderLibrary;
    MTL::Buffer* _argBuffer;

    MTL::Buffer* _frameData[3];
    float _angle;
    int _frame;

    dispatch_semaphore_t _semaphore;
    static const int kMaxFramesInFlight;

public:
    explicit Renderer(MTL::Device* device);
    ~Renderer();

    void buildShaders();
    void buildBuffers();
    void buildFrameData();
    void draw(MTK::View* view);
};


#endif //METAL_PLAYGROUND_RENDERER_HPP
