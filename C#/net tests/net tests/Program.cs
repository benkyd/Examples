using System;
using System.Net;
using System.IO;
using System.Diagnostics;

namespace net_tests
{
    class Program
    {
        const int _max = 5;
        static void Main(string[] args)
        {
            try
            {


                // Get url.
                string url = "www.apple.com";

                // Report url.
                Console.ForegroundColor = ConsoleColor.White;
                Console.WriteLine("... PageTimeTest: times web pages");
                Console.ResetColor();
                Console.WriteLine("Testing: {0}", url);

                // Fetch page.
                using (WebClient client = new WebClient())
                {
                    File.Create(url);

                    // Set gzip.
                    client.Headers["Accept-Encoding"] = "gzip";

                    // Download.
                    // ... Do an initial run to prime the cache.
                    byte[] data = client.DownloadData(url);

                    // Start timing.
                    Stopwatch stopwatch = Stopwatch.StartNew();

                    // Iterate.
                    for (int i = 0; i < Math.Min(100, _max); i++)
                    {
                        data = client.DownloadData(url);
                    }

                    // Stop timing.
                    stopwatch.Stop();

                    // Report times.
                    Console.WriteLine("Time required: {0} ms",
                        stopwatch.Elapsed.TotalMilliseconds);
                    Console.WriteLine("Time per page: {0} ms",
                        stopwatch.Elapsed.TotalMilliseconds / _max);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                Console.WriteLine("[Done]");
                Console.ReadLine();
            }
        }
    }
}
