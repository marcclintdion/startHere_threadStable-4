#ifdef WIN32 
void load_rocks_o20_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_rocks_o20 = FreeImage_GetFileType(rocks_o20_FilePath, 0);                       
    dib_rocks_o20   = FreeImage_Load(fifmt_rocks_o20, rocks_o20_FilePath, 0);                    
    temp_rocks_o20  = dib_rocks_o20;                                                      
    dib_rocks_o20   = FreeImage_ConvertTo32Bits(temp_rocks_o20);                          
    FreeImage_Unload(temp_rocks_o20);                                            

    if( dib_rocks_o20 != NULL )                                                    
    {                                                                       
        pixels_rocks_o20 = (BYTE*)FreeImage_GetBits(dib_rocks_o20);                       
    }                                                                     

    rocks_o20_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_rocks_o20_FromSystemRAM(void)                                          
{                                                                           
    if( dib_rocks_o20 != NULL )                                                    
    {                                                                       
        free(pixels_rocks_o20);                                                    
        FreeImage_Unload(dib_rocks_o20);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
