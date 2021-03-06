//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
GLint getOpenGL_ExtentionValues;


//=======================================================================================
GLuint countFrames = 0;

time_t  gameTimerInit;
time_t  gameTimerEnd;



//=======================================================================================


GLfloat       screenRatio;

//=======================================================================================


GLuint        boxCount                                               =  1;
GLuint        selectedModel                                          =  0;     

GLfloat       collisionBoxArray[500][32];                                    
                         
            
//=======================================================================================

var           fieldOfView                                            =     30.0;
var           fieldOfView_SHADOW                                     =     30.0;
//---------------------------------------------------------------------------------------
GLsizei       resize_SHADOW_FBO = 1;
GLsizei       resize_LIGHTS_FBO = 1;


//---------------------------------------------------------------------------------------
var           moveSet[]                                              =  {  61.0,  40.5, -2.0, 1.0};
var           currentSetHeight                                       =     0.0;

//---------------------------------------------------------------------------------------

//=============================================================================================
#ifdef WIN32
var           eyePosition[]                                          =  {  0, 0.0, -21.6179, 0.0};
#endif
//--------------
#ifdef __APPLE__
var           eyePosition[]                                          =  {  0, 0.0, -21.6179, 0.0};
#endif 
//--------------------------------------
var           eyePosition_SHADOW[]                                   =  {0.3006, -0.8517, 19.3797, 0};
var           spinShadow[]                                           =  {0.0, 0.0};

var           angleShadows[]                                         =  {1.0, .5, 0.0, -65};



//var           adjustNearFar_CAMERA[]                               =  {  2, 40.0 };
//var           adjustNearFar_LIGHT[]                                =  {  2, 40.0 };

var           adjustNearFar_CAMERA[]                                 =  {  2, 200.0 };
var           adjustNearFar_LIGHT[]                                  =  {  2, 200.0 };
//=============================================================================================
#ifdef WIN32
var           shadowBias                                             =  0.000193972;
#endif
//--------------
#ifdef __APPLE__
var           shadowBias                                             =     0.000193972*2.0;
#endif 
//=============================================================================================

var           rotateModelWithMiddleMouse[]                           =  {  0.0, 0.0};
var           zoomModelWithMiddleMouse                               =     0.0;
var           moveModelWithMiddleMouse[]                             =  {  0.0, 0.0};
//---------------------------------------------------------------------------------------


//===============================================================================================================
//===============================================================================================================
var           scaleScreenAlignedQuadRatio                            = 0.0;
var           inverseScreenRatio;     
//------------------------------------                       
    #ifdef WIN32
        var         display_00_MOVE[]                                =  { -1.0,  1.0,  0.0,  1.0};
    #endif
    //--------------
    #ifdef __APPLE__
        var         display_00_MOVE[]                                =  {  1.0,  1.0,  0.0,  1.0};
    #endif
    //--------------------------------
    var             display_00_SCALE[]                               =  {  1.0,  1.0,  0.0,  1.0};
//===============================================================================================================
GLuint  configureShader = 12;                      
        
//===============================================================================================================


//=================================================================================================================
//-----------------------------------------------------------------------------------------------------------------                      
//=================================================================================================================  
        

        
    //#####################################__FBO__#######################################################          
    //=====================================================================================================      
    //#include "_SHADERS/drawMainColor_FBO/drawMainColor_FBO_GLOBALS.cpp"
    //=====================================================================================================
    #include    "_SHADERS/drawMainColor_PRIMARY_FBO/drawMainColor_PRIMARY_FBO_GLOBALS.cpp"
    //=====================================================================================================

    //#include "_SHADERS/hardEdgeShadow_FBO/hardEdgeShadow_FBO_GLOBALS.cpp"
    //=====================================================================================================
    #include "_SHADERS/generic_FBO/generic_FBO_GLOBALS.cpp"
    //=====================================================================================================
    //#include "_SHADERS/softDiffuse_FBO/softDiffuse_FBO_GLOBALS.cpp"
    //=====================================================================================================
    //#####################################__SHADERS__#####################################################
    //=====================================================================================================
    //#include    "_SHADERS/SHADOWS/flatten_3D_shadow_SHADER_GLOBALS.cpp"//_FOR_USE_AS_A_MASK
    //=====================================================================================================
    #include "_SHADERS/finalComposite/finalComposite_SHADER_GLOBALS.cpp"
    //=====================================================================================================
    #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_GLOBALS.cpp"
    //=====================================================================================================
    //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_SHADER_GLOBALS.cpp"
    //=====================================================================================================
    #include "_SHADERS/copyFBO/copyFBO_SHADER_GLOBALS.cpp"
    //====================================================================================     
    #include "_SHADERS/PowerVR_blur/PowerVR_blur_SHADER_GLOBALS.cpp"
    //====================================================================================
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    
        
   //#include "_SHADERS/softDiffuse_SHADER/softDiffuse_SHADER_GLOBALS.cpp"
    //====================================================================================                                 
    #include "_SHADERS/mixShaders/bronzePlastic/bronzePlastic_SHADER_GLOBALS.cpp"
    //====================================================================================   
    #include "_SHADERS/mixShaders/stoneBronze/stoneBronze_SHADER_GLOBALS.cpp"
    //====================================================================================       
    #include "_SHADERS/baseColor/baseColor_SHADER_GLOBALS.cpp"
    //==================================================================================== 
    #include "_SHADERS/baseColor_x4tex/baseColor_x4tex_SHADER_GLOBALS.cpp"
    //====================================================================================     
                                     
                                 
                                 
    //#####################################__MODELS__#######################################################
    //=========================================================================
    #include    "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_GLOBALS.cpp"
    //=========================================================================    
    //=========================================================================    
    //-------------------------------------------------------------------------
    //========================================================================= 

    //===============================================================================================================
    //---------------------------------------------------------------------------------------------------------------
    //===============================================================================================================
    GLfloat areaBounds[] = {41, 34};//this works well for normal view and should be used for machines with low memory
    //=========================================================================     
    #include "_MODEL_FOLDERS_/o11/o11_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_/o18/o18_GLOBALS.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_/o17/o17_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o19\o19_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o12\o12_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o10\o10_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o1\o1_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o21\o21_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_B\o8_B_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_A\o8_A_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o5\o5_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o15\o15_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o16\o16_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o6\o6_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o14\o14_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o13\o13_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o7\o7_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o20\o20_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o9\o9_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o2\o2_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o4\o4_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o3\o3_GLOBALS.cpp"  
    //========================================================================= 
                                        //=========================================================================                                         
                                        //-------------------------------------------------------------------------
                                        //========================================================================= 
                                        #include "LOCATIONS/AREA_POSITIONS.cpp"
                                        //========================================================================= 
                                        GLfloat heightBounds[] = {4, 4};
                                        GLuint   groundLevel_SpheresActive =     0;
                                        GLfloat  groundLevelAdjust         =     0.0;
                                        GLfloat  spheres_TOTAL_HEIGHT      =     0.0;
                                        GLfloat  delta_HEIGHT              =     0.0;
                                        #include "LOCATIONS/HEIGHT_SPHERES_GLOBALS.cpp"
                                        //=========================================================================                                         
                                        //-------------------------------------------------------------------------
                                        //========================================================================= 

    //========================================================================= 
    #include "_MODEL_FOLDERS_\Cube\Cube_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\domeTree_x4\domeTree_x4_GLOBALS.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o21\rocks_o21_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o15\rocks_o15_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o17\rocks_o17_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o18\rocks_o18_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o19\rocks_o19_GLOBALS.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o20\rocks_o20_GLOBALS.cpp"  


    //========================================================================= 
    //#include "_MODEL_FOLDERS_\copperEntrance\copperEntrance_GLOBALS.cpp"  

