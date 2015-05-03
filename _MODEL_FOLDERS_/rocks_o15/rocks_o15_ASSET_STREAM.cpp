#ifdef WIN32 
void load_rocks_o15_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_rocks_o15 = FreeImage_GetFileType(rocks_o15_FilePath, 0);                       
    dib_rocks_o15   = FreeImage_Load(fifmt_rocks_o15, rocks_o15_FilePath, 0);                    
    temp_rocks_o15  = dib_rocks_o15;                                                      
    dib_rocks_o15   = FreeImage_ConvertTo32Bits(temp_rocks_o15);                          
    FreeImage_Unload(temp_rocks_o15);                                            

    if( dib_rocks_o15 != NULL )                                                    
    {                                                                       
        pixels_rocks_o15 = (BYTE*)FreeImage_GetBits(dib_rocks_o15);                       
    }                                                                     

    rocks_o15_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_rocks_o15_FromSystemRAM(void)                                          
{                                                                           
    if( dib_rocks_o15 != NULL )                                                    
    {                                                                       
        free(pixels_rocks_o15);                                                    
        FreeImage_Unload(dib_rocks_o15);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
