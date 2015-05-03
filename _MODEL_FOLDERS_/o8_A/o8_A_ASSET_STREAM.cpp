#ifdef WIN32 
void load_o8_A_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o8_A = FreeImage_GetFileType(o8_A_FilePath, 0);                       
    dib_o8_A   = FreeImage_Load(fifmt_o8_A, o8_A_FilePath, 0);                    
    temp_o8_A  = dib_o8_A;                                                      
    dib_o8_A   = FreeImage_ConvertTo32Bits(temp_o8_A);                          
    FreeImage_Unload(temp_o8_A);                                            

    if( dib_o8_A != NULL )                                                    
    {                                                                       
        pixels_o8_A = (BYTE*)FreeImage_GetBits(dib_o8_A);                       
    }                                                                     

    o8_A_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o8_A_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o8_A != NULL )                                                    
    {                                                                       
        free(pixels_o8_A);                                                    
        FreeImage_Unload(dib_o8_A);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
