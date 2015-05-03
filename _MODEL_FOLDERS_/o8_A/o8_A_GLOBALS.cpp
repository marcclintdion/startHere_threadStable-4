void  load_o8_A_FromHDtoSystemRAM(void*);                                     
void  delete_o8_A_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o8_A;                                                
FIBITMAP            *dib_o8_A;                                                
FIBITMAP           *temp_o8_A;                                                
BYTE             *pixels_o8_A;                                                  
//-------------------------------------------------------------
bool   o8_A_isLoadedFromDriveAndWaiting             = false;                  
bool   o8_A_isLoaded                                = false;                  
char  *o8_A_FilePath;                                                         
bool   o8_A_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o8_A_POSITION[]             = { -118.563011f, -1.555251f, 8.530622f, 1.0 }; 
GLfloat o8_A_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o8_A_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o8_A_VBO; 
GLuint o8_A_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o8_A_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o8_A_boundingBox[6]; 

//===================================================================================================================
void load_o8_A_VBOs(void)  
{ 
      #include    "o8_A.cpp" 
      glGenBuffers(1,              &o8_A_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o8_A_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o8_A), o8_A, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o8_A_INDICES.cpp"   
      glGenBuffers(1,              &o8_A_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o8_A_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o8_A_INDICES), o8_A_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
