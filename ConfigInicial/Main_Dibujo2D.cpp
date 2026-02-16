/* Barco Núñez Claudia Citlali
* No. de Cuenta: 422067621
* Fecha: 15-02-2026
* Practica 2. Dibujo de primitivas en 2D
/*/


#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 2. Claudia Barco", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Vertices de la mariposa
	float vertices[] = {

		//Lado izquierdo
		// mitad de ala superior, bordes
		-0.525f,  0.575f, 0.0f,    0.0f, 0.0f, 1.0f,  // 0
		-0.55f,   0.39f,  0.0f,    0.0f, 0.0f, 1.0f,  // 1
		-0.51f,   0.245f,0.0f,     0.0f, 0.0f, 1.0f,  // 2
		-0.49f,   0.13f,  0.0f,    0.0f, 0.0f, 1.0f,  // 3
		-0.4f,    0.005f, 0.0f,    0.0f, 0.0f, 1.0f,  // 4
		-0.18f,   0.35f,  0.0f,    0.0f, 0.0f, 1.0f,  // 5


		// antena
		-0.06f,   0.34f,  0.0f,    1.0f, 1.0f, 0.0f,  // 6
		-0.025f,   0.14f,  0.0f,    1.0f, 1.0f, 0.0f,  // 7

		// cuerpo
		0.0f,     0.18f,  0.0f,    1.0f, 1.0f, 0.0f,  // 8
		-0.05f,   0.1f,   0.0f,    1.0f, 1.0f, 0.0f,  // 9
		-0.02f,   0.0f,   0.0f,    1.0f, 1.0f, 0.0f,  // 10
		-0.04f,  -0.3f,   0.0f,    1.0f, 1.0f, 0.0f,  // 11
		0.0f,    -0.35f,  0.0f,    1.0f, 1.0f, 0.0f,  // 12

	

		// mitad de ala superior, interior
		-0.425f,  0.41f,  0.0f,    1.0f, 1.0f, 0.0f,  // 13
		-0.48f,   0.37f,  0.0f,    1.0f, 1.0f, 0.0f,  // 14
		-0.345f,  0.29f,  0.0f,    1.0f, 1.0f, 0.0f,  // 15
		-0.345f,  0.16f,  0.0f,    1.0f, 1.0f, 0.0f,  // 16
		-0.48f,   0.24f,  0.0f,    1.0f, 1.0f, 0.0f,  // 17
		-0.18f,   0.20f,  0.0f,    1.0f, 1.0f, 0.0f,  // 18
		-0.18f,   0.06f,  0.0f,    1.0f, 1.0f, 0.0f,  // 19

		// mitad de ala inferior, bordes
		-0.375f, -0.05f,   0.0f,    0.0f, 0.0f, 1.0f,  // 20
		-0.45f,  -0.14f,  0.0f,    0.0f, 0.0f, 1.0f,  // 21
		-0.44f,  -0.3f,   0.0f,    0.0f, 0.0f, 1.0f,  // 22
		-0.29f,  -0.42f,  0.0f,    0.0f, 0.0f, 1.0f,  // 23
		-0.04f,  -0.15f,  0.0f,    0.0f, 0.0f, 1.0f,  // 24

		// mitad de ala inferior, interior
		-0.24f,  -0.07f,  0.0f,    1.0f, 1.0f, 0.0f,  // 25
		-0.3f,   -0.09f,  0.0f,    1.0f, 1.0f, 0.0f,  // 26
		-0.375f, -0.11f,  0.0f,    1.0f, 1.0f, 0.0f,  // 27
		-0.375f, -0.25f,  0.0f,    1.0f, 1.0f, 0.0f,  // 28
		-0.29f,  -0.19f,  0.0f,    1.0f, 1.0f, 0.0f,  // 29
		-0.24f,  -0.355f, 0.0f,    1.0f, 1.0f, 0.0f,  // 30
		-0.19f,  -0.25f,  0.0f,    1.0f, 1.0f, 0.0f,  // 31
		-0.11f,  -0.16f,  0.0f,    1.0f, 1.0f, 0.0f,   // 32

        //Lado derecho
		// mitad de ala superior, bordes
		0.525f,  0.575f, 0.0f,    0.0f, 0.0f, 1.0f,  // 33
		0.55f,   0.39f,  0.0f,    0.0f, 0.0f, 1.0f,  // 34
		0.51f,   0.245f, 0.0f,    0.0f, 0.0f, 1.0f,  // 35
		0.49f,   0.13f,  0.0f,    0.0f, 0.0f, 1.0f,  // 36
		0.4f,    0.005f, 0.0f,    0.0f, 0.0f, 1.0f,  // 37
		0.18f,   0.35f,  0.0f,    0.0f, 0.0f, 1.0f,  // 38

		// antena 
		0.06f,   0.34f,  0.0f,    1.0f, 1.0f, 0.0f,  // 39
		0.025f,  0.14f,  0.0f,    1.0f, 1.0f, 0.0f,  // 40

		// cuerpo
		-0.0f,   0.18f,  0.0f,    1.0f, 1.0f, 0.0f,  // 41
		0.05f,   0.1f,   0.0f,    1.0f, 1.0f, 0.0f,  // 42
		0.02f,   0.0f,   0.0f,    1.0f, 1.0f, 0.0f,  // 43
		0.04f,  -0.3f,   0.0f,    1.0f, 1.0f, 0.0f,  // 44
		-0.0f,  -0.35f,  0.0f,    1.0f, 1.0f, 0.0f,  // 45

		// mitad de ala superior, interior
		0.425f,  0.41f,  0.0f,    1.0f, 1.0f, 0.0f,  // 46
		0.48f,   0.37f,  0.0f,    1.0f, 1.0f, 0.0f,  // 47
		0.345f,  0.29f,  0.0f,    1.0f, 1.0f, 0.0f,  // 48
		0.345f,  0.16f,  0.0f,    1.0f, 1.0f, 0.0f,  // 49
		0.48f,   0.24f,  0.0f,    1.0f, 1.0f, 0.0f,  // 50
		0.18f,   0.20f,  0.0f,    1.0f, 1.0f, 0.0f,  // 51
		0.18f,   0.06f,  0.0f,    1.0f, 1.0f, 0.0f,  // 52

		// mitad de ala inferior, bordes
		0.375f, -0.05f,  0.0f,    0.0f, 0.0f, 1.0f,  // 53
		0.45f,  -0.14f,  0.0f,    0.0f, 0.0f, 1.0f,  // 54
		0.44f,  -0.3f,   0.0f,    0.0f, 0.0f, 1.0f,  // 55
		0.29f,  -0.42f,  0.0f,    0.0f, 0.0f, 1.0f,  // 56
		0.04f,  -0.15f,  0.0f,    0.0f, 0.0f, 1.0f,  // 57

		// mitad de ala inferior, interior
		0.24f,  -0.07f,  0.0f,    1.0f, 1.0f, 0.0f,  // 58
		0.3f,   -0.09f,  0.0f,    1.0f, 1.0f, 0.0f,  // 59
		0.375f, -0.11f,  0.0f,    1.0f, 1.0f, 0.0f,  // 60
		0.375f, -0.25f,  0.0f,    1.0f, 1.0f, 0.0f,  // 61
		0.29f,  -0.19f,  0.0f,    1.0f, 1.0f, 0.0f,  // 62
		0.24f,  -0.355f, 0.0f,    1.0f, 1.0f, 0.0f,  // 63
		0.19f,  -0.25f,  0.0f,    1.0f, 1.0f, 0.0f,  // 64
		0.11f,  -0.16f,  0.0f,    1.0f, 1.0f, 0.0f   // 65

	};
	unsigned int indices[] = {

		//izquierda
		// cuerpo
		8,7, 7,9, 9,10, 10,11, 11,12,

		// antena
		6,7,

		// ala superior bordes
		0,1, 1,2, 2,3, 3,4, 0,5, 5,9, 4,10,

		//ala inferior bordes
		20,10, 20,21, 21,22, 22,23, 23,24,

		//interior superior
		0,13, 13,14, 14,15, 13,15, 13,5, 15,16, 16,17, 15,5, 15,18, 16,19, 18,19, 19,5, 
		14,1, 3,10, 4,10, 14,17, 17,2,

		//interior inferior
		20,25, 20,27,
		21,27,
		25,27, 27,28, 28,29, 26,29, 28,30, 30,10,31,29, 24,32,
		22,10, 21,10, 24,10,


		//derecha

		// cuerpo 
		41,40, 40,42, 42,43, 43,44, 44,45,
		
		// antena 
		39,40,

		// ala superior bordes
		33,34, 34,35, 35,36, 36,37, 33,38, 38,42, 37,43,

		// ala inferior bordes
		53,43, 53,54, 54,55, 55,56, 56,57,

		// interior superior
		33,46, 46,47, 47,48, 46,48, 46,38, 48,49, 49,50, 48,38,
		48,51, 49,52, 51,52, 52,38,
		47,34, 36,43, 37,43, 47,50, 50,35,

		// interior inferior
		53,58, 53,60,
		54,60,
		58,60, 60,61, 61,62, 59,62, 61,63, 63,43, 64,62, 57,65,
		55,43, 54,43, 57,43

		
	};




	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
        ourShader.Use();
        glBindVertexArray(VAO);


        glPointSize(5);
        glDrawArrays(GL_POINTS,0,66);

		//contorno
		glDrawElements(GL_LINES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);

        //cuerpo
		glDrawArrays(GL_TRIANGLE_FAN, 8, 5);
		glDrawArrays(GL_TRIANGLE_FAN, 41, 5);

        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}