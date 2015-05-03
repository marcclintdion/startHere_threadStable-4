#ifdef WIN32 
void load_Cube_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_Cube = FreeImage_GetFileType(Cube_FilePath, 0);                       
    dib_Cube   = FreeImage_Load(fifmt_Cube, Cube_FilePath, 0);                    
    temp_Cube  = dib_Cube;                                                      
    dib_Cube   = FreeImage_ConvertTo32Bits(temp_Cube);                          
    FreeImage_Unload(temp_Cube);                                            

    if( dib_Cube != NULL )                                                    
    {                                                                       
        pixels_Cube = (BYTE*)FreeImage_GetBits(dib_Cube);                       
    }                                                                     

    Cube_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_Cube_FromSystemRAM(void)                                          
{                                                                           
    if( dib_Cube != NULL )                                                    
    {                                                                       
        free(pixels_Cube);                                                    
        FreeImage_Unload(dib_Cube);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
