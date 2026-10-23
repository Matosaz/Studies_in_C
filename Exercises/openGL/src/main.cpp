#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // 1. Inicializa o GLFW
    if (!glfwInit()) {
        std::cerr << "Erro: falha ao inicializar o GLFW.\n";
        return -1;
    }

    // 2. Configura a versão do OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 3. Cria a janela
    GLFWwindow* window = glfwCreateWindow(
        800, 600, "Teste OpenGL - GLFW + GLAD", nullptr, nullptr
    );

    if (window == nullptr) {
        std::cerr << "Erro: falha ao criar a jane   la.\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 4. Inicializa o GLAD
    if (!gladLoadGLLoader(
            reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "Erro: falha ao inicializar o GLAD.\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }
    
    glViewPort(0, 0, 800, 600);

    // 5. Exibe informações da implementação OpenGL
    std::cout << "OpenGL inicializado com sucesso!\n";
    std::cout << "Versao: "
              << reinterpret_cast<const char*>(glGetString(GL_VERSION))
              << '\n';
    std::cout << "GPU/Renderer: "
              << reinterpret_cast<const char*>(glGetString(GL_RENDERER))
              << '\n';

    // 6. Loop principal
    while (!glfwWindowShouldClose(window)) {
        // Fecha a janela ao pressionar ESC
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }


        // Limpa o fundo
        glClearColor(0.08f, 0.10f, 0.16f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Desenha a janela na tela
        glfwSwapBuffers(window);
        
        glfwPollEvents();
    }

    // 7. Libera os recursos
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
