void  load_rocks_o17_FromHDtoSystemRAM(void*);                                     
void  delete_rocks_o17_FromSystemRAM(void); //The VOID pointer is a potential mistake,(it's not a thread function?)
//------------------------------------
FREE_IMAGE_FORMAT  fifmt_rocks_o17;                                                
FIBITMAP            *dib_rocks_o17;                                                
FIBITMAP           *temp_rocks_o17;                                                
BYTE             *pixels_rocks_o17;                                                  
//-------------------------------------------------------------
bool   rocks_o17_isLoadedFromDriveAndWaiting             = false;                  
bool   rocks_o17_isLoaded                                = false;                  
char  *rocks_o17_FilePath;                                                         
bool   rocks_o17_isActive                                = true;                    
//========================--------------------------========================

//===================================================================================================================
GLfloat rocks_o17_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat rocks_o17_ROTATION[]             = { 0.000000f, 0.000000f, 1.000000f, 0.000000f }; 
GLfloat rocks_o17_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//----------------------------------------------------------------- 
GLuint rocks_o17_VBO; 
GLuint rocks_o17_INDICES_VBO; 
//----------------------------------------------------------------- 
GLuint rocks_o17_COLORMAP; 


//----------------------------------------------------------------- 
GLfloat rocks_o17_boundingBox[6]; 

//===================================================================================================================
void load_rocks_o17_VBOs(void)  
{ 
      #include    "rocks_o17.cpp" 
      glGenBuffers(1,              &rocks_o17_VBO);  
      glBindBuffer(GL_ARRAY_BUFFER, rocks_o17_VBO);  
      glBufferData(GL_ARRAY_BUFFER, sizeof(rocks_o17), rocks_o17, GL_STATIC_DRAW);  
      glBindBuffer(GL_ARRAY_BUFFER, 0); 
      //------------------------------------------------------------------------------
      #include    "rocks_o17_INDICES.cpp"   
      glGenBuffers(1,              &rocks_o17_INDICES_VBO);  
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o17_INDICES_VBO);   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rocks_o17_INDICES), rocks_o17_INDICES, GL_STATIC_DRAW);   
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
      //========================================================================================================
} 
