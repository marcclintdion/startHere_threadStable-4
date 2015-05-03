void  load_domeTree_x4_FromHDtoSystemRAM(void*); 
void  delete_domeTree_x4_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_domeTree_x4; 
FIBITMAP            *dib_domeTree_x4; 
FIBITMAP           *temp_domeTree_x4; 
BYTE             *pixels_domeTree_x4;   
//-------------------------------------------------------------
bool   domeTree_x4_isLoadedFromDriveAndWaiting             = false; 
bool   domeTree_x4_isLoaded                                = false; 
char  *domeTree_x4_FilePath;                                        
bool   domeTree_x4_isActive                                = true;   
//===================================================================================================================
GLfloat domeTree_x4_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat domeTree_x4_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat domeTree_x4_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 0.000000f };

//----------------------------------------------------------------- 
GLuint domeTree_x4_VBO; 
GLuint domeTree_x4_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint domeTree_x4_COLORMAP; 
//----------------------------------------------------------------- 
GLfloat domeTree_x4_boundingBox[6]; 

//===================================================================================================================
void load_domeTree_x4_VBOs(void)  
{ 
      #include    "domeTree_x4.cpp" 
      glGenBuffers(1,              &domeTree_x4_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, domeTree_x4_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(domeTree_x4), domeTree_x4, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "domeTree_x4_INDICES.cpp"   
      glGenBuffers(1,              &domeTree_x4_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, domeTree_x4_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(domeTree_x4_INDICES), domeTree_x4_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
