void  load_rocks_o15_FromHDtoSystemRAM(void*);                                     
void  delete_rocks_o15_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_rocks_o15;                                                
FIBITMAP            *dib_rocks_o15;                                                
FIBITMAP           *temp_rocks_o15;                                                
BYTE             *pixels_rocks_o15;                                                  
//-------------------------------------------------------------
bool   rocks_o15_isLoadedFromDriveAndWaiting             = false;                  
bool   rocks_o15_isLoaded                                = false;                  
char  *rocks_o15_FilePath;                                                         
bool   rocks_o15_isActive                                = true;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat rocks_o15_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat rocks_o15_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat rocks_o15_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint rocks_o15_VBO; 
GLuint rocks_o15_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint rocks_o15_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat rocks_o15_boundingBox[6]; 

//===================================================================================================================
void load_rocks_o15_VBOs(void)  
{ 
      #include    "rocks_o15.cpp" 
      glGenBuffers(1,              &rocks_o15_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, rocks_o15_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(rocks_o15), rocks_o15, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "rocks_o15_INDICES.cpp"   
      glGenBuffers(1,              &rocks_o15_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o15_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rocks_o15_INDICES), rocks_o15_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
