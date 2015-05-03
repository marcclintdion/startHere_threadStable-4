      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
                                          
      gaussianBlur_9x_Vertical_SHADER = glCreateProgram();                                                                                                         
                                                                   
      const GLchar *vertexSource_gaussianBlur_9x_Vertical =                                                                                                        
      //===============================================================================================================================  
      "    #define highp                                                                                                                 \n"                           

      "    attribute highp vec4 position;                                                                                                      \n"
      "    attribute highp vec2 texture;                                                                                                       \n"
      "    uniform   highp float blurRadius;                                                                                                   \n"
      "    uniform   highp float screenRatio;                                                                                                  \n"
    
                                    
      "    varying highp vec2 v_texCoord;                                                                                                      \n"
      "    varying highp vec2 v_blurTexCoords[9];                                                                                              \n"
 
      "    void main()                                                                                                                   \n" 
      "    {                                                                                                                             \n" 
      
      "           highp vec2 Pos;                                                                                                              \n"
      "           Pos = sign(position.xy);                                                                                               \n"  
 
      "           gl_Position = highp vec4(Pos, 0.0, 1.0);                                                                                     \n"
                  //Image-space
      "           v_texCoord = Pos * 0.4 + 0.5;                                                                                          \n"  
   
      "           v_texCoord = texture;                                                                                                  \n" 
                  //------------------
      "           v_blurTexCoords[ 0] = v_texCoord + highp vec2(0.0, -4.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 1] = v_texCoord + highp vec2(0.0, -3.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 2] = v_texCoord + highp vec2(0.0, -2.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 3] = v_texCoord + highp vec2(0.0, -1.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 4] = v_texCoord + highp vec2(0.0,  0.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 5] = v_texCoord + highp vec2(0.0,  1.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 6] = v_texCoord + highp vec2(0.0,  2.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 7] = v_texCoord + highp vec2(0.0,  3.0 * (blurRadius)* screenRatio) ;                                                       \n"
      "           v_blurTexCoords[ 8] = v_texCoord + highp vec2(0.0,  4.0 * (blurRadius)* screenRatio) ;                                                       \n"
     
      
      "    }\n";                                                                                                                             
      //===============================================================================================================================                                                                    
      gaussianBlur_9x_Vertical_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(gaussianBlur_9x_Vertical_SHADER_VERTEX, 1, &vertexSource_gaussianBlur_9x_Vertical, NULL);                                                                        
      glCompileShader(gaussianBlur_9x_Vertical_SHADER_VERTEX);                                                                                                     
      //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      const GLchar *fragmentSource_gaussianBlur_9x_Vertical =                                                                                                            
      //=============================================================================================================================== 
      " #ifdef GL_ES                                                                                                          \n"                       
      " #else                                                                                                                 \n"                       
      " #define highp                                                                                                         \n"                       
      " #endif                                                                                                                \n"                       

      "       uniform sampler2D s_texture;                                                                                     \n" 
      
      "       uniform highp float adjust;                                                                                     \n"  

      "       varying highp vec2 v_texCoord;                                                                                     \n"
      "       varying highp vec2 v_blurTexCoords[9];                                                                                     \n" 
 
      "       void main()                                                                                                           \n" 
      "       {                                                                                                                     \n" 
  
      "           highp float tempShadow = 0.0;                                                                                     \n"   
  
      "     highp float checkPixelColor = texture2D(s_texture, v_texCoord).w;                                                       \n" 
     
//      "     if(checkPixelColor > (0.6+adjust))                                                                                               \n"  
//      "     {                                                                                                                       \n" 
  
  
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 0]).w * 0.05;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 1]).w * 0.09;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 2]).w * 0.12;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 3]).w * 0.15;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 4]).w * 0.16;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 5]).w * 0.15;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 6]).w * 0.12;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 7]).w * 0.09;                              \n" 
      "           tempShadow += texture2D(s_texture, v_blurTexCoords[ 8]).w * 0.05;                              \n" 
//      "     }                                                                                                    \n" 
  
      "           gl_FragColor = highp vec4(texture2D(s_texture, v_texCoord).xyz, tempShadow);                                                                                     \n"
   
      "    }\n";                                                                                                                                   

//====================================================================================================================================      

      //---------------------------------------------------------------------                                                                         
      gaussianBlur_9x_Vertical_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(gaussianBlur_9x_Vertical_SHADER_FRAGMENT, 1, &fragmentSource_gaussianBlur_9x_Vertical, NULL);                                                                          
      glCompileShader(gaussianBlur_9x_Vertical_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(gaussianBlur_9x_Vertical_SHADER, gaussianBlur_9x_Vertical_SHADER_VERTEX);                                                                                              
      glAttachShader(gaussianBlur_9x_Vertical_SHADER, gaussianBlur_9x_Vertical_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(gaussianBlur_9x_Vertical_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(gaussianBlur_9x_Vertical_SHADER, 1, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(gaussianBlur_9x_Vertical_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(gaussianBlur_9x_Vertical_SHADER, gaussianBlur_9x_Vertical_SHADER_VERTEX);                                                                                              
      glDetachShader(gaussianBlur_9x_Vertical_SHADER, gaussianBlur_9x_Vertical_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(gaussianBlur_9x_Vertical_SHADER_VERTEX);                                                                                                            
      glDeleteShader(gaussianBlur_9x_Vertical_SHADER_FRAGMENT);                                                                                                          
      //-----------------------------------------------------------------------------------------------------------              
      
      UNIFORM_TEXTURE_gaussianBlur_9x_Vertical            = glGetUniformLocation(gaussianBlur_9x_Vertical_SHADER,   "s_texture");                                               
      UNIFORM_blurRadius_gaussianBlur_9x_Vertical         = glGetUniformLocation(gaussianBlur_9x_Vertical_SHADER,   "blurRadius");       
      UNIFORM_screenRatio_gaussianBlur_9x_Vertical        = glGetUniformLocation(gaussianBlur_9x_Vertical_SHADER,   "screenRatio");      
      UNIFORM_adjust_gaussianBlur_9x_Vertical             = glGetUniformLocation(gaussianBlur_9x_Horizontal_SHADER,   "adjust");                                                                                                                 

      
      //-----------------------------------------------------------------------------------------------------------              
                                                                                                                          
      //-----------------------------------------------------------------------------------------------------------            
