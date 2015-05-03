void  load_o17_FromHDtoSystemRAM(void*);                                     
void  delete_o17_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o17;                                                
FIBITMAP            *dib_o17;                                                
FIBITMAP           *temp_o17;                                                
BYTE             *pixels_o17;                                                  
//-------------------------------------------------------------
bool   o17_isLoadedFromDriveAndWaiting             = false;                  
bool   o17_isLoaded                                = false;                  
char  *o17_FilePath;                                                         
bool   o17_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o17_POSITION[]             = { -40.452869f, -33.734550f, 3.070155f, 1.0 }; 
GLfloat o17_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o17_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o17_VBO; 
GLuint o17_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o17_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o17_boundingBox[6]; 

//===================================================================================================================
void load_o17_VBOs(void)  
{ 
      #include    "o17.cpp" 
      glGenBuffers(1,              &o17_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o17_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o17), o17, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o17_INDICES.cpp"   
      glGenBuffers(1,              &o17_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o17_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o17_INDICES), o17_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
