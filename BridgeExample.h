#ifndef BRIDGEEXAMPLE_H
#define BRIDGEEXAMPLE_H
#include <iostream>

struct Renderer
{
    virtual void render(float x, float y, float radius) = 0;
};

struct VectorRender : Renderer
{
    void render(float x, float y, float radius) override
    {
        std::cout << "Vector render, radius - " << radius << std::endl;
    }
};

struct RustRender : Renderer
{
    void render(float x, float y, float radius) override
    {
        std::cout << "Rust render, radius - " << radius << std::endl;
    }
};

struct Shape
{
protected:
    Renderer &renderer;
    Shape(Renderer &renderer) : renderer(renderer){}

public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : Shape
{
    float x, y, radius;
    Circle(Renderer &renderer, float x, float y, float radius) : Shape(renderer), x(x), y(y), radius(radius) {}

public:
    void draw() override
    {
        renderer.render(x, y, radius);
    }
    void resize(float factor) override
    {
        radius *= factor;
    }
};

void runBridge()
{
    RustRender rr;
    Circle ruster_circle(rr, 10.f, 20.f, 1.f);
    ruster_circle.draw();
    ruster_circle.resize(10);
    ruster_circle.draw();

}

#endif // BRIDGEEXAMPLE_H
