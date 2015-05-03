#ifdef WIN32 
void load_gemini_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_gemini = FreeImage_GetFileType(gemini_FilePath, 0);                       
    dib_gemini   = FreeImage_Load(fifmt_gemini, gemini_FilePath, 0);                    
    temp_gemini  = dib_gemini;                                                      
    dib_gemini   = FreeImage_ConvertTo32Bits(temp_gemini);                          
    FreeImage_Unload(temp_gemini);                                            

    if( dib_gemini != NULL )                                                    
    {                                                                       
        pixels_gemini = (BYTE*)FreeImage_GetBits(dib_gemini);                       
    }                                                                     

    gemini_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_gemini_FromSystemRAM(void)                                          
{                                                                           
    if( dib_gemini != NULL )                                                    
    {                                                                       
        free(pixels_gemini);                                                    
        FreeImage_Unload(dib_gemini);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      
