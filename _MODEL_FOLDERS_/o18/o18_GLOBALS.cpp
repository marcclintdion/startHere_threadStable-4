void  load_o18_FromHDtoSystemRAM(void*);                                     
void  delete_o18_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_o18;                                                
FIBITMAP            *dib_o18;                                                
FIBITMAP           *temp_o18;                                                
BYTE             *pixels_o18;                                                  
//-------------------------------------------------------------
bool   o18_isLoadedFromDriveAndWaiting             = false;                  
bool   o18_isLoaded                                = false;                  
char  *o18_FilePath;                                                         
bool   o18_isActive                                = false;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat o18_POSITION[]             = { -2.611154f, -35.533051f, 3.211108f, 1.0 }; 
GLfloat o18_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat o18_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint o18_VBO; 
GLuint o18_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint o18_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat o18_boundingBox[6]; 

//===================================================================================================================
void load_o18_VBOs(void)  
{ 
      #include    "o18.cpp" 
      glGenBuffers(1,              &o18_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, o18_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(o18), o18, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "o18_INDICES.cpp"   
      glGenBuffers(1,              &o18_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o18_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o18_INDICES), o18_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
