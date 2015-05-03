#include <fstream.h>
using namespace std;


    baseColor_x4tex_SHADER = glCreateProgram();                                                                                     
    //----------------------------------------------------                                                                  
    vertexSource_baseColor_x4tex   = readShaderFile( "_SHADERS/baseColor_x4tex/baseColor_x4tex_vert.cpp" );                                                                                  
    fragmentSource_baseColor_x4tex = readShaderFile( "_SHADERS/baseColor_x4tex/baseColor_x4tex_frag.cpp" );                                                                                

        
        //=======================================================================================================================                   
        baseColor_x4tex_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( baseColor_x4tex_SHADER_VERTEX, 1, (const GLchar**)&vertexSource_baseColor_x4tex, NULL );                                        
        glCompileShader( baseColor_x4tex_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        baseColor_x4tex_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( baseColor_x4tex_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_baseColor_x4tex, NULL );                                    
        glCompileShader(baseColor_x4tex_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( baseColor_x4tex_SHADER, baseColor_x4tex_SHADER_VERTEX );                                                        
        glAttachShader( baseColor_x4tex_SHADER, baseColor_x4tex_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(baseColor_x4tex_SHADER,   0, "position");                                                              
        glBindAttribLocation(baseColor_x4tex_SHADER,   1, "normal");                                                            
        glBindAttribLocation(baseColor_x4tex_SHADER,   2, "uv0");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( baseColor_x4tex_SHADER_VERTEX);                                                                             
        glDeleteShader( baseColor_x4tex_SHADER_FRAGMENT);                                                                           
        glLinkProgram(baseColor_x4tex_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    

        UNIFORM_PROJECTION_MATRIX_baseColor_x4tex                         = glGetUniformLocation(baseColor_x4tex_SHADER, "projectionMatrix");          
        UNIFORM_MODELVIEW_MATRIX_baseColor_x4tex                          = glGetUniformLocation(baseColor_x4tex_SHADER, "modelViewMatrix");                  
        //----------------------------------------      
        UNIFORM_TEX_COLOR_baseColor_x4tex                                 = glGetUniformLocation(baseColor_x4tex_SHADER, "ColorMAP");  
        //----------------------------------------                                                                  
        UNIFORM_UV_ADJUST_baseColor_x4tex                                 = glGetUniformLocation(baseColor_x4tex_SHADER, "UV_Adjust");  


//######################################################
#include "settings.cpp"











