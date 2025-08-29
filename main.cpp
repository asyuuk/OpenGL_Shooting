#include"Renderer.h"
#include<memory>

int main()
{
	glm::Renderer renderer;
	renderer.Run(); // Start the renderer
	renderer.MainLoop();

	return 0;
}