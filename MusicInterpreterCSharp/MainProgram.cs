using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MusicInterpreterCSharp
{
    class MainProgram
    {
        public static void Main(string[] args)
        {
            var prop = WaveFileManager.LoadFile(args[0]);
            Console.WriteLine("FileSize : " + prop.m_FileSize);
        }
    }
}
