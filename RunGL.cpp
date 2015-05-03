#define var GLfloat
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))//to_use-> COUNT_OF( floorTile_2m_INDICES)
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//=======================================================================================================================
   
  
    
#ifdef WIN32
        #define   glGenerateMipmap       glGenerateMipmapEXT
        #define   glGenFramebuffers      glGenFramebuffersEXT
        #define   glBindFramebuffer      glBindFramebufferEXT
        #define   glDeleteFramebuffers   glDeleteFramebuffersEXT        
        #define   glFramebufferTexture2D glFramebufferTexture2DEXT
         
         
         
        #define   STRICT
        #define   WIN32_LEAN_AND_MEAN
        #include <windows.h>
        #include <process.h>
        #include <stdlib.h>
        #include <stdio.h>
        #include <sys/stat.h>
        #include <iostream.h>
        #include <fstream.h>
        #include <vector>
        //using namespace std; //___used for string object

        //-----------------------------------------------------------------------------
        #include <GL/gl.h>
        #include <GL/glu.h>
        #include "headerFiles/glext.h"
        #include "headerFiles/glext_Init_A.cpp"
        //=====================================
        void InitGL(void);
        void RenderGL(void);
        void KillALData(void);
        void ProcessKeyboard(void);
        void shutDownGL(void); 
        bool CreateDummyGLWindow();       
        //=========================
        int  screenWidth;
        int  screenHeight; 
        int  viewWidth;
        int  viewHeight;        
        //----------------------------------------------------------------------
        GLfloat  Pass_MIDDLE_Mouse[2];       //AT_SHUTDOWN_THESE_VALUES_ARE_BEING_PRINTED_THE_FILE->loadMouseSettings.cpp
        GLfloat  Pass_MIDDLE_CONTROL_Mouse;  //                                   
        GLfloat  Pass_MIDDLE_SHIFT_Mouse[2]; //AT_RUNTIME_THESE_ARE_BEING_LOADED_INTO->WGL_ARB_multiSample.h      
        //-------------------------------
        bool keys[256], keypressed[256];
        bool mkeyIsReset = true;
        
        //#include "cpp/winInit.cpp"THESE_2_ARE_FILE_FINDER_NOTES_SO_THAT_MUCH_OLDER_MODULES_CAN_BE_FOUND_AND_MERGED_WITHOUT_FORMAT_CHANGE_CONFUSION
        //#include "cpp/configureWindow.cpp"
        bool                g_isFullScreen;
        #include "cpp/WGL_ARB_multisample.h"
        //-------------------------------

        #include "headerFiles/VSync.h"
        
        #include <windows.h>
       




        //=========================================================
        //void ConfigureAndLoadTexture(GLubyte *textureData, GLuint &currentTextureHandle);
        #include "headerFiles/glaux.h"
        #include "headerFiles/FreeImage.h"
#endif






unsigned char *readShaderFile( const char *fileName )
{
    FILE *file = fopen( fileName, "r" );

    if( file == NULL )
    {
        MessageBox( NULL, "Cannot open shader file!", "ERROR",
            MB_OK | MB_ICONEXCLAMATION );
		return 0;
    }

    struct _stat fileStats;

    if( _stat( fileName, &fileStats ) != 0 )
    {
        MessageBox( NULL, "Cannot get file stats for shader file!", "ERROR",
                    MB_OK | MB_ICONEXCLAMATION );
        return 0;
    }

    unsigned char *buffer = new unsigned char[fileStats.st_size];

	int bytes = fread( buffer, 1, fileStats.st_size, file );

    buffer[bytes] = 0;

	fclose( file );

	return buffer;
} 









/*
//===========================
#include "cpp/Timer.cpp"
Timer timer, t1;
float readTime;
//===========================
*/


//#include <cstdlib>
#include <sys/timeb.h>

int getMilliCount(){
	struct timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if(nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

int start = 0;
int milliSecondsElapsed = 0;
//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

bool sound_API_selector = 0;//_0_is_openAL_/_1_is_fMod

//=========================================================
GLfloat frequency[512];
GLfloat audioRotation[] = {1.0, 0.0, 1.0, 0.0};
GLfloat directionSoundTravels = 1.0;
GLuint  selectFrequency = 4;
//----------------------------------------------
#ifdef __APPLE__
        //--------------
        int  viewWidth;
        int  viewHeight;
        //----------------------------------------------
        #include "AUDIO/openAL_iOS/openAL_iOS_GLOBALS.cpp"
        //-----------------------------------------------
//        #import "fmod.hpp"
//        #import "fmod_errors.h"
        GLfloat frequency_fMod_iOS[64];

//        #include "AUDIO/fMod_iOS/fMod_iOS_GLOBALS.cpp" //_____found_in_EAGLView

        

#endif
//=========================================================
#ifdef WIN32
        
       #include "AUDIO/openAL_WIN/openAL_WIN_GLOBALS.cpp"

        
#endif
//=========================================================




//=======================================================================================================================

GLfloat adjust_w = 1.0;

#include <math.h>
  
//=======================================================================================================================

#include "MATRIX_MATH.cpp"

//=======================================================================================================================


//--------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
        extern GLuint msaaFramebuffer;
        extern GLuint viewRenderbuffer;

        bool iOS_MSAA_IS_ON = true;
        
        void RenderGL(void);
        void InitGL  (void);
        void shutDownGL(void);
      
        #ifdef __APPLE__
               GLuint  viewFramebuffer;
        #endif
          
        //-------------------------------------------------------------------------------


        GLuint m_uiShadowMapTexture;
        GLuint m_uiFrameBufferObject;





var     shadowTextureMatrix[16];
var     moveSetMatrix[16];
var     modelWorldMatrix[16];
var     moveSet_x_modelWorldMatrix[16];//THIS_IS_INTERMEDIATE_STEP_USED_TO_REMOVE_MULTIPLICATION_FROM_2_CHAINS_OF_VERTEX_SHADER_MULTIPLIES
var     modelRotationINVmatrix[16];
var     projectionMatrix[16];
var     viewMatrix[16];
var     viewRotateMatrix[16];
var     modelViewMatrix[16];

var     modelRotationMatrix[16];


var     shadowBiasMatrix[] = {0.5, 0.0, 0.0, 0.0, 
                              0.0, 0.5, 0.0, 0.0, 
                              0.0, 0.0, 0.5, 0.0, 
                              0.5, 0.5, 0.5, 1.0};

var     shadowProjectionMatrix[16];
var     shadowViewMatrix[16];
var     shadowModelWorld[16];


var     invertViewMatrix[16];

var     tempMatrix_A[16];    
var     tempMatrix_B[16]; 
var     tempMatrix_C[16]; 
var     tempMatrix_D[16]; 
var     tempMatrix_E[16]; 
//============================================================================================================================
var     moveShadowPivot_Z = 0.0;
//============================================================================================================================


GLuint MAX_THREADS  = 0;



#include "GLOBALS.cpp"


float deltaMoveSet           = 0.3;
  





//============================================================================================================================
void setupTransforms_MainColor(void)
{
        
        LoadIdentity(viewMatrix);
        Translate(viewMatrix,             eyePosition[0], 
                                          eyePosition[1], 
                                          eyePosition[2]);

        
        LoadIdentity(viewRotateMatrix);
        //-----------------------------   
        Rotate(viewRotateMatrix, 1.0, 0.0, 0.0, rotateModelWithMiddleMouse[0]);
        Rotate(viewRotateMatrix, 0.0, 0.0, 1.0, -rotateModelWithMiddleMouse[1]);        
}

//============================================================================================================================
void setupTransforms_Shadows(void)
{

        LoadIdentity(shadowViewMatrix);
        //-------------------------------------------------
/*       Translate(shadowViewMatrix,       eyePosition_SHADOW[0],
                                          eyePosition_SHADOW[1],
                                          eyePosition_SHADOW[2]);
*/      
LookAt(shadowViewMatrix, eyePosition_SHADOW[0], eyePosition_SHADOW[1], eyePosition_SHADOW[2] ,  0, 0, 0, 0.0f, 1.0f, 0.0f);

}

void ColorRenderMatrixFunctions(void)
{

    MultiplyMatrix(modelViewMatrix, viewMatrix, modelWorldMatrix);
    //------------------------------------------------------------    
    LoadIdentity(tempMatrix_A);    
    MultiplyMatrix(tempMatrix_A, viewMatrix, viewRotateMatrix);    
    //---------------------------------------------------------------------    
    MultiplyMatrix(moveSet_x_modelWorldMatrix, moveSetMatrix, modelWorldMatrix);    
    //---------------------------------------------------------------------    
    LoadIdentity(tempMatrix_B);     
    MultiplyMatrix(tempMatrix_B,  shadowTextureMatrix, moveSet_x_modelWorldMatrix);     
    //---------------------------------------------------------------------    
    LoadIdentity(tempMatrix_C);     
    MultiplyMatrix(tempMatrix_C,  projectionMatrix, tempMatrix_A);       
    //---------------------------------------------------------------------    
    LoadIdentity(tempMatrix_D);     
    MultiplyMatrix(tempMatrix_D,  tempMatrix_C, moveSet_x_modelWorldMatrix);     
    
    //----------------------------------------------------------------------------------------------------------    
    LoadIdentity(shadowTextureMatrix);
    MultiplyMatrix(shadowTextureMatrix, shadowBiasMatrix, shadowProjectionMatrix);    
    MultiplyMatrix(shadowTextureMatrix, shadowTextureMatrix, shadowViewMatrix);    //_MULTIPLY THESE TO A TEMP MATRIX TO AVOID ROUND OFF ERRORS   //USES MORE CODE WITH INCREASED PRECISION 
    //----------------------------------------------------------------------------------------------------------
   
    LoadIdentity(tempMatrix_E);
    MultiplyMatrix(tempMatrix_E, viewRotateMatrix, modelRotationMatrix);
    //----------------------------------------------------------------------------------------------------------
    LoadIdentity(modelRotationINVmatrix);
    InvertMatrix(modelRotationINVmatrix, tempMatrix_E);
     //----------------------------------------------------------------------------------------------------------     
}





//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

GLuint     stone_Fresnel_TEX;  //_HAD_TO_MAKE_THIS_GLOBAL_FOR_NOW_SO_SHADER_SELECTOR_FUNCTION_CAN_SEE_IT

var shaderNumber = 0;

void SelectShader(var shaderNumber)
{
        
    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   1)
    {
        #include "_SHADERS/copyFBO/copyFBO_SHADER_RENDER.cpp"
    }    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   2)//gaussianBlur_9x_Horizontal
    {
        //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Horizontal_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   3)//gaussianBlur_9x_Vertical
    {
        //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Vertical_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   4)
    {
        
    }    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   5)
    {
        //#include "_SHADERS/softDiffuse_SHADER/softDiffuse_SHADER_RENDER.cpp"
    }    
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==   6)
    {
        #include "_SHADERS/PowerVR_blur/PowerVR_blur_SHADER_RENDER.cpp"
    }    
    //--------------------------------------------------------------------------------------
    
    
    
    //==================================================================================================          
    if(shaderNumber ==   10)
    {
        #include "_SHADERS/finalComposite/finalComposite_SHADER_RENDER.cpp"
    }         
    //--------------------------------------------------------------------------------------  


    if(shaderNumber ==  11)
    {
        #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_RENDER.cpp"
    }  
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==  13)
    {
        #include "_SHADERS/mixShaders/bronzePlastic/bronzePlastic_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==  14)
    {
        #include "_SHADERS/mixShaders/stoneBronze/stoneBronze_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==  15)
    {
        #include "_SHADERS/baseColor/baseColor_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    if(shaderNumber ==  16)
    {
        #include "_SHADERS/baseColor_x4tex/baseColor_x4tex_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------






}

//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================



void InitGL( void )//__BEGIN_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
{
        
        #include "tier2_GLOBALS.cpp"
        
        //==========================================================================
        #ifdef WIN32
            #include "cpp/setPixelFormat.cpp"
            #include "headerFiles/glext_Init_B.cpp"
            alutInit(NULL, 0);
            //-------------------------------------
            SetVSyncState(true);
            //-----------------------------------------------------------------------------
                        rotateModelWithMiddleMouse[0] = Pass_MIDDLE_Mouse[0];
                        rotateModelWithMiddleMouse[1] = Pass_MIDDLE_Mouse[1];
                        //-----------------------------------------------------------------
                        zoomModelWithMiddleMouse      = Pass_MIDDLE_CONTROL_Mouse;
                        //-----------------------------------------------------------------     
                        moveModelWithMiddleMouse[0]   = Pass_MIDDLE_SHIFT_Mouse[0];
                        moveModelWithMiddleMouse[1]   = Pass_MIDDLE_SHIFT_Mouse[1];
                        //-----------------------------------------------------------------       
       
        //=================
        #endif
                   
                   
time(&gameTimerInit);                
                   
start = getMilliCount();
                
//################################################################################################################################
/*
        #ifdef __APPLE__
        
                if(sound_API_selector == 0)
                {
                        #include "AUDIO/openAL_iOS/openAL_iOS_Init.cpp"
                }        
                if(sound_API_selector == 1)
                {        
                        //#include "AUDIO/fMod_iOS/fMod_iOS_Init.cpp" //_____found_in_EAGLView
                }
        
        #endif
        //=========================================================
        #ifdef WIN32
                
                if(sound_API_selector == 0)
                {
                        #include "AUDIO/openAL_WIN/openAL_WIN_Init.cpp"
                }
                
                if(sound_API_selector == 1)
                {    
                        #include "AUDIO/fMod_WIN/fMod_WIN_Init.cpp"
                }
        
        #endif
*/



//========================================================================
#ifdef WIN32
                screenRatio                = (GLfloat)viewWidth / (GLfloat)viewHeight;
#endif
//--------------
#ifdef __APPLE__
                screenRatio                = (GLfloat)viewHeight/(GLfloat)viewWidth; //___WIDESCREEN(LANDSCAPE)  //__look for perspective adjustment at start of render block
#endif
//========================================================================    
 
//NSLog(@"screenRatio: %f", (GLfloat)screenRatio);
   
//=====================================================================================================
//-----------------------------------------------------------------------------------------------------
//_____________________________________________________________________________________________________
GLfloat adjustToResolution = (GLfloat)viewWidth/(GLfloat)viewHeight;
//===================================================================
#ifdef WIN32
        display_00_SCALE[0] = 1.0/(GLfloat)viewWidth * (GLfloat)viewWidth * adjustToResolution*4.52/10;   
        display_00_SCALE[1] = display_00_SCALE[0]; 
        
        //------------------------------------------------------------------------------------------------
        scaleScreenAlignedQuadRatio   = (GLfloat)viewWidth / (GLfloat)viewHeight;
        //-----------------------------------------------------------------------
        inverseScreenRatio            = 1.0 / (GLfloat)viewWidth * (GLfloat)viewHeight; 
        display_00_MOVE[0]           += inverseScreenRatio * display_00_SCALE[0] * 0.5; 
        display_00_MOVE[1]           -=  display_00_SCALE[1] * 0.5;
        //------------------------------------------------------------------------------------------------
        GLfloat skipTouchIncrement = display_00_SCALE[1] / scaleScreenAlignedQuadRatio;
        display_00_MOVE[0] += skipTouchIncrement;
#endif       
//========================= 
#ifdef __APPLE__
        display_00_SCALE[0] = 1.0/(GLfloat)viewWidth * (GLfloat)viewWidth * adjustToResolution*4.52/10*4.0;   
        display_00_SCALE[1] = display_00_SCALE[0]; 
        
        //-----------------------------------------------------------------------
        scaleScreenAlignedQuadRatio   =  (GLfloat)viewWidth / (GLfloat)viewHeight;
        //-----------------------------------------------------------------------
        inverseScreenRatio            = (1.0 / (GLfloat)viewHeight) * viewWidth; 
        display_00_MOVE[1]           -=  inverseScreenRatio * display_00_SCALE[0] * 0.5; 
        display_00_MOVE[0]           -=  display_00_SCALE[1] * 0.5 ;        
        //------------------------------------------------------------------------------------------------
        GLfloat skipTouchIncrement = display_00_SCALE[1] * scaleScreenAlignedQuadRatio;
        display_00_MOVE[1] -= skipTouchIncrement;
#endif        
//_____________________________________________________________________________________________________   
//-----------------------------------------------------------------------------------------------------   
//=====================================================================================================   


//======================================================================================================================
//======================================================================================================================
#ifdef WIN32        
        glGenTextures(1, &m_uiShadowMapTexture);
	    //------------
        glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth  * resize_SHADOW_FBO, 
                                                           (GLsizei)viewHeight * resize_SHADOW_FBO, 
                                                            0, GL_DEPTH_COMPONENT,  GL_UNSIGNED_INT,  NULL);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);        
        //------------------------------------------------------------------
	    glGenFramebuffers(1, &m_uiFrameBufferObject);
	    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
        //---------------------
        glDrawBuffer(GL_NONE);//_ON_SOME_MACHINES_THIS_IS_REQUIRED / ON_SOME_IT_FAILS
        glReadBuffer(GL_NONE);//_SAME_AS_ABOVE
	    //---------------------
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);     
        glBindFramebuffer(GL_FRAMEBUFFER, 0);        
#endif
//===================== NSLog(@"viewWidth: %f", (GLfloat)viewWidth);   
#ifdef __APPLE__
        glGenTextures(1, &m_uiShadowMapTexture);
	    //------------
        glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 2000, 
                                                           1000, 
                                                           0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, 0);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //------------------------------------------------------------------
	    glGenFramebuffers(1, &m_uiFrameBufferObject);
	    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
        //---------------------
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);     
        glBindFramebuffer(GL_FRAMEBUFFER, 0);        
 #endif
//======================================================================================================================
//======================================================================================================================


//=======================
#include "INITIALIZE.cpp" //NOW USING FBO TO DISPLAY SCENE
//=======================



//==============================================================================
    #ifdef WIN32   
        atexit(KillALData);//_tell_openAL_to_run_KillALData_function_at_shutdown 
#endif    
        
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
        
//====================================================================================================================================

}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@






//==========================
#include "STREAM_ASSETS.cpp"
//==========================








//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================



void RenderGL(void)
{
//t1.start();
//============
countFrames ++;
//============





  
 



//========================================  
#include "LOCATIONS/ACTIVE_AREA_TEST.cpp" 
//========================================    
groundLevel_SpheresActive = 0;
delta_HEIGHT  = 0;
groundLevelAdjust = 0;
#include "LOCATIONS/HEIGHT_SPHERE_TEST.cpp" 
//========================================          



if(groundLevel_SpheresActive != 0)
{
    spheres_TOTAL_HEIGHT = groundLevelAdjust / float(groundLevel_SpheresActive); //_AVERAGE_OF_ALL_DETECTED_SPHERES_FOR_ALL_ACTIVE_AREAS
}

delta_HEIGHT  = 0.0 - spheres_TOTAL_HEIGHT; 

if(delta_HEIGHT < moveSet[2])
{
    moveSet[2] -= 0.11;
}
if(delta_HEIGHT > moveSet[2])
{
    moveSet[2] += 0.11;
}

    

    
    
    
    
    
    
    if(keys[VK_F8] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {       
       
         ofstream diagnostics("diagnostics.cpp");
                
                  
                  diagnostics << "groundLevelAdjust           =       " <<  groundLevelAdjust           << "                            \n";   
                  diagnostics << "groundLevel_SpheresActive   =       " <<  groundLevel_SpheresActive   << "                            \n";   
                  
                  diagnostics << "currentSetHeight            =       " <<  currentSetHeight            << "                            \n";   
                  diagnostics << "delta_HEIGHT                =       " <<  delta_HEIGHT        << "                            \n";   

                  diagnostics << "moveSet[2]                  =       " <<  moveSet[2]                  << "                            \n";   

    }

//=======================================================================================================================

      
                        //=================================================================
                        #ifdef __APPLE__   
                        //--------------         
                                //eyePosition[0] -= PassTouchMovement[0];
                                //eyePosition[1] -= PassTouchMovement[1];
                                //eyePosition[2] -= PassTouchMovement[2];                   
                        
                                //PassTouchMovement[0] = 0.0;
                                //PassTouchMovement[1] = 0.0;
                                //PassTouchMovement[2] = 0.0;
                        
                        //--------------                        
                        #endif 
                        //=================================================================
                                      
                        //=================================================================        
                        #ifdef WIN32  
                        //------------
                                rotateModelWithMiddleMouse[0] = Pass_MIDDLE_Mouse[0];
                                rotateModelWithMiddleMouse[1] = Pass_MIDDLE_Mouse[1];
                                //-------------------------------------------------------
                                zoomModelWithMiddleMouse = Pass_MIDDLE_CONTROL_Mouse;
                                //-------------------------------------------------------
                                moveModelWithMiddleMouse[0] = Pass_MIDDLE_SHIFT_Mouse[0];
                                moveModelWithMiddleMouse[1] = Pass_MIDDLE_SHIFT_Mouse[1];
                        //------------ 
                        #endif            
                        //=================================================================  
    
    



//============================================================================================================================       
//turnTable += 0.1;

        
      
LoadIdentity(moveSetMatrix);
//Translate(moveSetMatrix, moveSet[0], moveSet[1],moveSet[2]);




//====================================================================================================================================
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
//====================================================================================================================================
        glEnable(GL_DEPTH_TEST);
        glDepthMask(1);
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); 
        glDepthFunc(GL_LESS);
        glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);   

        #include "runDepth.cpp"
        
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
	    //glDepthMask(0);
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); 
        //glDepthFunc(GL_EQUAL);    
//====================================================================================================================================
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
//====================================================================================================================================
  
//=============================================================================================================== 
//=============================================================================================================== 
/*
    glBindFramebuffer(GL_FRAMEBUFFER, softDiffuse_FBO);//softDiffuse_FBO_TEXTURE
    //==========================================
            shaderNumber = 5;  
    #include "softDiffuse.cpp" 
    //==========================================
    glBindFramebuffer(GL_FRAMEBUFFER, 0);  
*/  

//==============================================================================================================================================
//==============================================================================================================================================
//========================================================###########---------------###########=================================================
//========================================================###########__MAIN_RENDER__###########=================================================
//========================================================###########---------------###########=================================================
//==============================================================================================================================================
//==============================================================================================================================================



    glBindFramebuffer(GL_FRAMEBUFFER, drawMainColor_PRIMARY_FBO);//drawMainColor_PRIMARY_FBO_COLOR_TEXTURE, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE
    //==========================================

    #include "drawMainColor.cpp"


#include "LOCATIONS/domeTrees_RENDER.cpp"
/*
shaderNumber = 16;
//================
domeTree_x4_POSITION[0] = 0.0;
adjust_UVs[0] =  0.0; adjust_UVs[1] =  0.0; //__________________This should be done in the vertex shader//_instead-> pass the mix factor based on area/position
#include "_MODEL_FOLDERS_\domeTree_x4\domeTree_x4_RENDER.cpp"     
//-----------------------------------------------------------      
domeTree_x4_POSITION[0] = 1.5;
adjust_UVs[0] = 0.0; adjust_UVs[1] =  0.5; 
#include "_MODEL_FOLDERS_\domeTree_x4\domeTree_x4_RENDER.cpp"     
//-----------------------------------------------------------     
domeTree_x4_POSITION[0] = 3.0;
adjust_UVs[0] =  0.5; adjust_UVs[1] =  0.0; 
#include "_MODEL_FOLDERS_\domeTree_x4\domeTree_x4_RENDER.cpp"     
//-----------------------------------------------------------      
domeTree_x4_POSITION[0] = 4.5;
adjust_UVs[0] = 0.5; adjust_UVs[1] =  0.5; 
#include "_MODEL_FOLDERS_\domeTree_x4\domeTree_x4_RENDER.cpp"     
//-----------------------------------------------------------      
*/    
    
    
    
    
    //==========================================
    glBindFramebuffer(GL_FRAMEBUFFER, 0);  


//==============================================================================================================================================
//==============================================================================================================================================
//========================================================###########---------------###########=================================================
//========================================================###########__MAIN_RENDER__###########=================================================
//========================================================###########---------------###########=================================================
//==============================================================================================================================================
//==============================================================================================================================================










/*
//=============================================================================================================== 
//=============================================================================================================== 
    glBindFramebuffer(GL_FRAMEBUFFER, hardEdgeShadow_TEXTURE); //hardEdgeShadow_TEXTURE
    //----------------------------------------------------------------
        glActiveTexture (GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_COLOR_TEXTURE);
        shaderNumber = 1;        
        //---------------  
        #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//=============================================================================================================== 
*/



       #include "_SHADERS/PowerVR_blur/PowerVR_blur_RENDER.cpp"




//=================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------
//=================================================================================================================================
#ifdef __APPLE__ //=======================================================
                  if(iOS_MSAA_IS_ON)
                  {
                      glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);     
                  }else 
                  {
                      glBindFramebuffer(GL_FRAMEBUFFER, viewRenderbuffer);  
                  }
#endif //=================================================================

    //==================================__FINAL_COMPOSITE__===============================
    glActiveTexture (GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, drawMainColor_PRIMARY_FBO_RAW_DEPTH_TEXTURE);
    //----------------------------
    glActiveTexture (GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
    //----------------------------    
    glActiveTexture (GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, generic_01_TEXTURE);//
    //---------------------------------------------------------------------
    shaderNumber = 10;
    #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"
    //==================================__FINAL_COMPOSITE__===============================


/*
    
    glBindFramebuffer(GL_FRAMEBUFFER, drawMainColor_FBO);
    const GLenum discards[]  = {GL_COLOR_ATTACHMENT0,GL_DEPTH_ATTACHMENT};
    glDiscardFramebufferEXT(GL_FRAMEBUFFER,2,discards);
   
    glBindFramebuffer(GL_FRAMEBUFFER, shadow_01_blur_HorizontalPass_fboId);
    const GLenum discards2[]  = {GL_COLOR_ATTACHMENT0};
    glDiscardFramebufferEXT(GL_FRAMEBUFFER,1,discards2);
    
    glBindFramebuffer(GL_FRAMEBUFFER, shadow_01_blur_VerticalPass_fboId);
    const GLenum discards3[]  = {GL_COLOR_ATTACHMENT0};
    glDiscardFramebufferEXT(GL_FRAMEBUFFER,1,discards3);
*/
//=================================================================================================================================
//---------------------------------------------------------------------------------------------------------------------------------
//=================================================================================================================================


         //t1.stop();
        //readTime = t1.getElapsedTimeInMilliSec();
        
        
time(&gameTimerEnd);

milliSecondsElapsed = getMilliSpan(start);

#ifdef __APPLE__
NSLog(@"milliSecondsElapsed: %i", (int)milliSecondsElapsed);
#endif
   
}//_END_RenderGL()//#####################################################################################################


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

#ifdef WIN32
void ProcessKeyboard(void)
{
/*  
    if (keys['T'] && tKeyIsReset && g_isFullScreen == true)
    {
             g_isFullScreen = false;
             tKeyIsReset = false;
    }
    else
    {
             g_isFullScreen = true;
    }      
             
             
             
             
             if (!keys['R'])
             {
                   tKeyIsReset = true;
             }      
*/    
 

    
  
    //=====================================================================
    if (keys['R'] && rKeyIsReset)
    {
             #include "_SHADERS/baseColor/baseColor_SHADER_INIT.cpp"      
             rKeyIsReset = false;
    }  
             if (!keys['R'])
             {
                   rKeyIsReset = true;
             }    
    
    //=================================================================================
  
  
    if (keys[VK_NUMPAD4] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             bronzePlastic_LIGHT1_POS[0]         -=  0.1112;
    }
    if (keys[VK_NUMPAD6] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             bronzePlastic_LIGHT1_POS[0]         +=  0.1112;
    }    
    if (keys[VK_NUMPAD8] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             bronzePlastic_LIGHT1_POS[1]         += 0.1112;
    } 
    if (keys[VK_NUMPAD2] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             bronzePlastic_LIGHT1_POS[1]         -=  0.1112;
    }
    if (keys[VK_NUMPAD9] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             bronzePlastic_LIGHT1_POS[2]         +=  0.1112;
    }
    if (keys[VK_NUMPAD7] && !keys[VK_SHIFT] && !keys[VK_CONTROL])  
    {
             bronzePlastic_LIGHT1_POS[2]         -=  0.1112;
    }
   //--------------------------------------------------------------------------
  
  
    //=================================================================================================================      
    
    #include "KEYBOARD/mainRoomControls.cpp"
 
   

   
    //=======================================================================================    
    //--------------------------------------------------------------------------    
    //======================================__LIGHTING__======================

    //-----------------------------------------------------------

/*   
    //-----------------------------------------------------------    
    if (keys['M'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            shinyRubber_1_bronzePlastic             +=  0.05;
    }
    if (keys['N'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            shinyRubber_1_bronzePlastic             -=  0.05;
    }     
  
    //-----------------------------------------------------------
    if (keys['X'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            shinyStone_0_stoneBronze             +=   1.0;
    }
    if (keys['Z'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            shinyStone_0_stoneBronze             -=   1.0;
    }    
    //-----------------------------------------------------------
   
    //-----------------------------------------------------------    
    if (keys['V'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            shinyStone_1_stoneBronze              +=  1.0;
    }
    if (keys['C'] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
            shinyStone_1_stoneBronze              -=  1.0;
    }     
  
 */ 
  
  
  
  
      //======================================__LIGHTING__======================    
    //--------------------------------------------------------------------------       
    //=================================================================================================================    

  
    if(keys[VK_F8] && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
        
         ofstream tier2_GLOBALS("tier2_GLOBALS.cpp");
                
                  tier2_GLOBALS << "eyePosition[0]       =      " <<  eyePosition[0] << ";                                                             \n";   
                  tier2_GLOBALS << "eyePosition[1]       =      " <<  eyePosition[1] << ";                                                             \n";                   
                  tier2_GLOBALS << "eyePosition[2]       =      " <<  eyePosition[2] << ";                                                             \n";   
                  tier2_GLOBALS << "eyePosition[3]       =      " <<  eyePosition[3] << ";                                                             \n";   
                  
                  
                  tier2_GLOBALS << "//========================================================                                                         \n";  

                  tier2_GLOBALS << "//------------                                                                                                     \n"; 
                  //========================================================================================================================================
                  //----------------------------------------------------------------------------------------------------------------------------------------
                  //========================================================================================================================================

/*
         ofstream stoneBronze_SETTINGS("_SHADERS/mixShaders/stoneBronze/settings.cpp");
                
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT0_POS[0]       =      " <<  stoneBronze_LIGHT0_POS[0] << ";                               \n";   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT0_POS[1]       =      " <<  stoneBronze_LIGHT0_POS[1] << ";                               \n";                   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT0_POS[2]       =      " <<  stoneBronze_LIGHT0_POS[2] << ";                               \n";   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT0_POS[3]       =        1.0;                                                                     \n";   
                 
                  stoneBronze_SETTINGS << "    //---------                                                                                                \n"; 
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT1_POS[0]       =      " <<  stoneBronze_LIGHT1_POS[0] << ";                               \n";   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT1_POS[1]       =      " <<  stoneBronze_LIGHT1_POS[1] << ";                               \n";                   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT1_POS[2]       =      " <<  stoneBronze_LIGHT1_POS[2] << ";                               \n";   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT1_POS[3]       =        1.0;                                                                     \n";   

                  stoneBronze_SETTINGS << "    //---------                                                                                                \n"; 
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT2_POS[0]       =      " <<  stoneBronze_LIGHT2_POS[0] << ";                               \n";   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT2_POS[1]       =      " <<  stoneBronze_LIGHT2_POS[1] << ";                               \n";                   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT2_POS[2]       =      " <<  stoneBronze_LIGHT2_POS[2] << ";                               \n";   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT2_POS[3]       =        1.0;                                                              \n";  

                  stoneBronze_SETTINGS << "    //---------                                                                                                \n"; 
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT3_POS[0]       =      " <<  stoneBronze_LIGHT3_POS[0] << ";                               \n";   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT3_POS[1]       =      " <<  stoneBronze_LIGHT3_POS[1] << ";                               \n";                   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT3_POS[2]       =      " <<  stoneBronze_LIGHT3_POS[2] << ";                               \n";   
                  stoneBronze_SETTINGS << "    stoneBronze_LIGHT3_POS[3]       =        1.0;                                                               \n";                               

                  stoneBronze_SETTINGS << "    //========================================================                                                 \n";  
                  stoneBronze_SETTINGS << "    shinyBronze_0_stoneBronze                =      " <<  shinyBronze_0_stoneBronze << ";                      \n";   
                  stoneBronze_SETTINGS << "    shinyBronze_1_stoneBronze                =      " <<  shinyBronze_1_stoneBronze << ";                      \n";   
                  stoneBronze_SETTINGS << "    shinyBronze_2_stoneBronze                =      " <<  shinyBronze_2_stoneBronze << ";                      \n";   
                  stoneBronze_SETTINGS << "    shinyBronze_3_stoneBronze                =      " <<  shinyBronze_3_stoneBronze << ";                      \n";   
                  stoneBronze_SETTINGS << "    //---------                                                                                                \n"; 
                  stoneBronze_SETTINGS << "    shinyStone_0_stoneBronze                 =      " <<  shinyStone_0_stoneBronze << ";                       \n";   
                  stoneBronze_SETTINGS << "    shinyStone_1_stoneBronze                 =      " <<  shinyStone_1_stoneBronze << ";                       \n";   
                  stoneBronze_SETTINGS << "    shinyStone_2_stoneBronze                 =      " <<  shinyStone_2_stoneBronze << ";                       \n";   
                  stoneBronze_SETTINGS << "    shinyStone_3_stoneBronze                 =      " <<  shinyStone_3_stoneBronze << ";                       \n";   
*/            
           
                  //========================================================================================================================================
                  //----------------------------------------------------------------------------------------------------------------------------------------
                  //========================================================================================================================================
         
         
         
         
         //########################################################################################################################
         ofstream outSettings("settings.cpp");
             
         
         //------------------------------------------------------------------------------------------------------------------------------        
         outSettings << "var          adjustShadowPos[]      =  {"    
                                  <<  adjustShadowPos[0]      << ", "   
                                  <<  adjustShadowPos[1]      << "};\n\n";   
         //------------------------------------------------------------------------------------------------------------------------------
        
         outSettings << "var         eyePosition[]    =  {"   
                                  << eyePosition[0] << ", "
                                  << eyePosition[1] << ", "
                                  << eyePosition[2] << ", "
                                  << eyePosition[3] << "};\n\n";
        
         //------------------------------------------------------------------------------------------------------------------------------
      
         outSettings << "var          bronzePlastic_LIGHT1_POS[]    =  {"   
                                  <<  bronzePlastic_LIGHT1_POS[0] << ", "
                                  <<  bronzePlastic_LIGHT1_POS[1] << ", "
                                  <<  bronzePlastic_LIGHT1_POS[2] << ", "
                                  <<  bronzePlastic_LIGHT1_POS[3] << "};\n\n";
       
        
         //-----------------------------------------------------------------------------------------------------------------       
         outSettings << "var          countFrames        =         "    
                                  <<  countFrames        << ";\n";   
         //-----------------------------------------------------------------------------------------------------------------       
         outSettings << "var          shinyRubber_1_bronzePlastic        =         "    
                                  <<  shinyRubber_1_bronzePlastic        << ";\n\n";   
         //-----------------------------------------------------------------------------------------------------------------       
         outSettings << "var          gameTimerEnd        =  "    
                                  <<  gameTimerEnd        << ";\n\n";   
         //-----------------------------------------------------------------------------------------------------------------       
         outSettings << "var          secondsElapsed        =  "    
                                  <<  (GLfloat)milliSecondsElapsed * 0.001        << ";\n\n";   
         //-----------------------------------------------------------------------------------------------------------------       
         
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var          countFrames                    =  "    
                                  <<  countFrames                    << ";\n\n";   
        
        
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "GLuint       getOpenGL_ExtentionValues                    =  "    
                                  <<  getOpenGL_ExtentionValues                    << ";\n\n";   
        
          
         //------------------------------------------------------------------------------------------------------------------------------
        
         outSettings << "var         eyePosition_SHADOW[]    =  {"   
                                  << eyePosition_SHADOW[0] << ", "
                                  << eyePosition_SHADOW[1] << ", "
                                  << eyePosition_SHADOW[2] << ", "
                                  << eyePosition_SHADOW[3] << "};\n\n";
        
        outSettings << "var           spinShadow[]       =  {"   
                                    << spinShadow[0]      << ", "
                                    << spinShadow[1]      << "};\n\n"; 
          
         //------------------------------------------------------------------------------------------------------------------------------

         //------------------------------------------------------------------------------------------------------------------------------
        
        outSettings << "var           rotateModelWithMiddleMouse[]       =  {"   
                                    << rotateModelWithMiddleMouse[0]      << ", "
                                    << rotateModelWithMiddleMouse[1]      << "};\n\n"; 
        
         //------------------------------------------------------------------------------------------------------------------------------
       
         outSettings << "var           moveSet[]       =  {"   
                                    << moveSet[0]      << ", "
                                    << moveSet[1]      << ", "
                                    << moveSet[2]      << ", 1.0};\n";                
        
         //------------------------------------------------------------------------------------------------------------------------------
    
    
   //----------------------------------------------------------------------------------------------------------------
        
    }//_END_F8

//=======================================================================================
//---------------------------------------------------------------------------------------
//_______________________________________________________________________________________
if(keys[VK_F9])
{
    GLsizei screenCaptureWidth  = (GLsizei)viewWidth; 
    GLsizei screenCaptureHeight = (GLsizei)viewHeight;        
                
    GLubyte *pixmap =(GLubyte *)malloc(screenCaptureWidth*screenCaptureHeight*4);
    
    glReadPixels(0,0,screenCaptureWidth,screenCaptureHeight,GL_BGRA,GL_UNSIGNED_BYTE,pixmap);
    
    FIBITMAP *texture = FreeImage_ConvertFromRawBits( pixmap, screenCaptureWidth, screenCaptureHeight, screenCaptureWidth*4, 32, 0xFF0000, 0x00FF00, 0x0000FF, true);    
    FreeImage_Save(FIF_BMP, texture, "AAAAA.bmp", 0);         
        
    free(pixmap);                 
}          
//_______________________________________________________________________________________
//---------------------------------------------------------------------------------------
//=======================================================================================



#include "KEYBOARD/keyboard_RESET.c"

    

    //=================================================================================================================    
    //--------------------------------------------------------------------------    
    //======================================__SELECT_MODEL======================
    if (keys[VK_OEM_PERIOD] && VK_OEM_PERIOD_KeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             selectedModel += 1;
             VK_OEM_PERIOD_KeyIsReset = false;   
    }
    //=============================================================    
    if (keys[VK_OEM_COMMA] && VK_OEM_COMMA_KeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
             selectedModel -= 1;
             VK_OEM_COMMA_KeyIsReset = false;   
    }
    //======================================__SELECT_MODEL__====================     
    //--------------------------------------------------------------------------
    //=================================================================================================================
    //=================================================================================================================
    //--------------------------------------------------------------------------     
    //======================================__BOX_COUNT__====================        
    if (keys[VK_PRIOR] && VK_PRIOR_KeyIsReset && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
         boxCount +=  1;
         VK_PRIOR_KeyIsReset  = false;
    }         
    if (keys[VK_NEXT]  && VK_NEXT_KeyIsReset  && !keys[VK_SHIFT] && !keys[VK_CONTROL])
    {
         boxCount -=  1;
         VK_NEXT_KeyIsReset   = false;    
    }       
    //======================================__BOX_COUNT__====================         
    //--------------------------------------------------------------------------       
    //=================================================================================================================   
    
    
     
   
}//_END_ProcessKeyboard()
#endif

//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================


void shutDownGL( void )
{

//=======================================================================================================================
//=======================================================================================================================
        #include "SHUTDOWN.cpp"
        
                                                               
}


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

#ifdef WIN32
void KillALData()
{
	alDeleteBuffers(1, &Buffer_dungeonWAV);
	alDeleteSources(1, &Source_dungeonWAV);
    alutExit();
}
#endif




