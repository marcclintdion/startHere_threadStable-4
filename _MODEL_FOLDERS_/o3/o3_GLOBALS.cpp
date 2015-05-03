void  load_o3_FromHDtoSystemRAM(void*);                                     
void  delete_o3_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o3;                                                
FIBITMAP            *dib_o3;                                                
FIBITMAP           *temp_o3;                                                
BYTE             *pixels_o3;                                                  
//-------------------------------------------------------------
bool   o3_isLoadedFromDriveAndWaiting             = false;                  
bool   o3_isLoaded                                = false;                  
char  *o3_FilePath;                                                         
bool   o3_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o3_POSITION[]             = { -40.185051f, 33.997780f, 17.332829f, 1.0 }; 
GLfloat o3_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o3_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o3_VBO; 
GLuint o3_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o3_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o3_boundingBox[6]; 

//===================================================================================================================
void load_o3_VBOs(void)  
{ 
      #include    "o3.cpp" 
      glGenBuffers(1,              &o3_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o3_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o3), o3, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o3_INDICES.cpp"   
      glGenBuffers(1,              &o3_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o3_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o3_INDICES), o3_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
