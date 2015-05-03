void  load_o2_FromHDtoSystemRAM(void*);                                     
void  delete_o2_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o2;                                                
FIBITMAP            *dib_o2;                                                
FIBITMAP           *temp_o2;                                                
BYTE             *pixels_o2;                                                  
//-------------------------------------------------------------
bool   o2_isLoadedFromDriveAndWaiting             = false;                  
bool   o2_isLoaded                                = false;                  
char  *o2_FilePath;                                                         
bool   o2_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o2_POSITION[]             = { -80.639679f, 35.091774f, 23.980324f, 1.0 }; 
GLfloat o2_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o2_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o2_VBO; 
GLuint o2_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o2_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o2_boundingBox[6]; 

//===================================================================================================================
void load_o2_VBOs(void)  
{ 
      #include    "o2.cpp" 
      glGenBuffers(1,              &o2_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o2_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o2), o2, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o2_INDICES.cpp"   
      glGenBuffers(1,              &o2_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o2_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o2_INDICES), o2_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
