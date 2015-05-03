#ifdef WIN32 
void load_o20_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o20 = FreeImage_GetFileType(o20_FilePath, 0);                       
    dib_o20   = FreeImage_Load(fifmt_o20, o20_FilePath, 0);                    
    temp_o20  = dib_o20;                                                      
    dib_o20   = FreeImage_ConvertTo32Bits(temp_o20);                          
    FreeImage_Unload(temp_o20);                                            

    if( dib_o20 != NULL )                                                    
    {                                                                       
        pixels_o20 = (BYTE*)FreeImage_GetBits(dib_o20);                       
    }                                                                     

    o20_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o20_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o20 != NULL )                                                    
    {                                                                       
        free(pixels_o20);                                                    
        FreeImage_Unload(dib_o20);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
