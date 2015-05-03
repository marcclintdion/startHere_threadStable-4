#ifdef WIN32 
void load_o16_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o16 = FreeImage_GetFileType(o16_FilePath, 0);                       
    dib_o16   = FreeImage_Load(fifmt_o16, o16_FilePath, 0);                    
    temp_o16  = dib_o16;                                                      
    dib_o16   = FreeImage_ConvertTo32Bits(temp_o16);                          
    FreeImage_Unload(temp_o16);                                            

    if( dib_o16 != NULL )                                                    
    {                                                                       
        pixels_o16 = (BYTE*)FreeImage_GetBits(dib_o16);                       
    }                                                                     

    o16_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o16_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o16 != NULL )                                                    
    {                                                                       
        free(pixels_o16);                                                    
        FreeImage_Unload(dib_o16);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
