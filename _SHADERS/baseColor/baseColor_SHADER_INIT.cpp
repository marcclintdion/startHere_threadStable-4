#include <fstream.h>
using namespace std;


    baseColor_SHADER = glCreateProgram();                                                                                     
    //----------------------------------------------------                                                                  
    vertexSource_baseColor   = readShaderFile( "_SHADERS/baseColor/baseColor_vert.cpp" );                                                                                  
    fragmentSource_baseColor = readShaderFile( "_SHADERS/baseColor/baseColor_frag.cpp" );                                                                                

        
        //=======================================================================================================================                   
        baseColor_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( baseColor_SHADER_VERTEX, 1, (const GLchar**)&vertexSource_baseColor, NULL );                                        
        glCompileShader( baseColor_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        baseColor_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( baseColor_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_baseColor, NULL );                                    
        glCompileShader(baseColor_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( baseColor_SHADER, baseColor_SHADER_VERTEX );                                                        
        glAttachShader( baseColor_SHADER, baseColor_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(baseColor_SHADER,   0, "position");                                                              
        glBindAttribLocation(baseColor_SHADER,   1, "normal");                                                            
        glBindAttribLocation(baseColor_SHADER,   2, "uv0");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( baseColor_SHADER_VERTEX);                                                                             
        glDeleteShader( baseColor_SHADER_FRAGMENT);                                                                           
        glLinkProgram(baseColor_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    

        UNIFORM_PROJECTION_MATRIX_baseColor                         = glGetUniformLocation(baseColor_SHADER, "projectionMatrix");          
        UNIFORM_MODELVIEW_MATRIX_baseColor                          = glGetUniformLocation(baseColor_SHADER, "modelViewMatrix");                  
        //-------------------------------      
        UNIFORM_TEX_COLOR_baseColor                                 = glGetUniformLocation(baseColor_SHADER, "ColorMAP");  


//######################################################
#include "settings.cpp"











