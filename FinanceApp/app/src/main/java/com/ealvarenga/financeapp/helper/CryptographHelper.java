package com.ealvarenga.financeapp.helper;

import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/**
 * Created by ealvarenga on 24/11/17.
 */

public class CryptographHelper {

    public static String getMD5(String content) {
        try {
            MessageDigest m = MessageDigest.getInstance("MD5");
            m.update(content.getBytes(),0, content.length());
            return new BigInteger(1,m.digest()).toString(16);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return null;

    }
}
