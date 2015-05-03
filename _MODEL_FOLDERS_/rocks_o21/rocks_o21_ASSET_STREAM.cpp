#ifdef WIN32 
void load_rocks_o21_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_rocks_o21 = FreeImage_GetFileType(rocks_o21_FilePath, 0);                       
    dib_rocks_o21   = FreeImage_Load(fifmt_rocks_o21, rocks_o21_FilePath, 0);                    
    temp_rocks_o21  = dib_rocks_o21;                                                      
    dib_rocks_o21   = FreeImage_ConvertTo32Bits(temp_rocks_o21);                          
    FreeImage_Unload(temp_rocks_o21);                                            

    if( dib_rocks_o21 != NULL )                                                    
    {                                                                       
        pixels_rocks_o21 = (BYTE*)FreeImage_GetBits(dib_rocks_o21);                       
    }                                                                     

    rocks_o21_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_rocks_o21_FromSystemRAM(void)                                          
{                                                                           
    if( dib_rocks_o21 != NULL )                                                    
    {                                                                       
        free(pixels_rocks_o21);                                                    
        FreeImage_Unload(dib_rocks_o21);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
