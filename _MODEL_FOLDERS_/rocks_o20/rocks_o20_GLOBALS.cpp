void  load_rocks_o20_FromHDtoSystemRAM(void*);                                     
void  delete_rocks_o20_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_rocks_o20;                                                
FIBITMAP            *dib_rocks_o20;                                                
FIBITMAP           *temp_rocks_o20;                                                
BYTE             *pixels_rocks_o20;                                                  
//-------------------------------------------------------------
bool   rocks_o20_isLoadedFromDriveAndWaiting             = false;                  
bool   rocks_o20_isLoaded                                = false;                  
char  *rocks_o20_FilePath;                                                         
bool   rocks_o20_isActive                                = true;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat rocks_o20_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat rocks_o20_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat rocks_o20_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint rocks_o20_VBO; 
GLuint rocks_o20_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint rocks_o20_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat rocks_o20_boundingBox[6]; 

//===================================================================================================================
void load_rocks_o20_VBOs(void)  
{ 
      #include    "rocks_o20.cpp" 
      glGenBuffers(1,              &rocks_o20_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, rocks_o20_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(rocks_o20), rocks_o20, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "rocks_o20_INDICES.cpp"   
      glGenBuffers(1,              &rocks_o20_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o20_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rocks_o20_INDICES), rocks_o20_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
