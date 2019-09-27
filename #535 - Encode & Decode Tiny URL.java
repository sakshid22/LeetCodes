// #535 - Encode & Decode Tiny URL.java

public class Codec {

    HashMap<Integer,Character> dict;
    HashMap<String, String> urls;
    
    public Codec()
    {
        dict = new HashMap<Integer, Character>();
        urls = new HashMap<String, String>();
        char c='0';
        int i =0;
        for( i=0; i<=9; i++)
        {
            dict.put(i,c); 
            c++;
        }
        c = 'a';
        while ( c<='z')
        {
            dict.put(i,c);
            c++;
            i++;
        }
        c ='A';
        while ( c<='Z')
        {
            dict.put(i,c);
            c++;
            i++;
        }
    }
    
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
      
        StringBuilder tmp = new StringBuilder();
        tmp.append("http://tinyurl.com/");
        for( int i=1; i<=6; i++)
        {
            int x = (i*longUrl.length())%62;
            char c = dict.get(x);
            tmp.append(c);
        }
        String shortendurl = tmp.toString();
        if(urls.containsKey(shortendurl)) 
            return shortendurl;
        urls.put(shortendurl, longUrl);
        return shortendurl;
        
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return urls.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));