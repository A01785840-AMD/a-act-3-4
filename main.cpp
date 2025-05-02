//
// Created by Angel Montemayor Davila, A01785840.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>


struct BSTNode {
    int accessCount;
    std::vector< std::string > ips;
    BSTNode *left;
    BSTNode *right;

    BSTNode(const int count, const std::string &ip) : accessCount(count), left(nullptr), right(nullptr) {
        ips.push_back(ip);
    }
};

BSTNode* insert(BSTNode *root, int count, const std::string &ip) {
    if (!root) return new BSTNode(count, ip);

    if (count < root->accessCount)
        root->left = insert(root->left, count, ip);
    else if (count > root->accessCount)
        root->right = insert(root->right, count, ip);
    else
        root->ips.push_back(ip);

    return root;
}

void printTopIPs(const BSTNode *root, int &remaining) {
    if (!root || remaining <= 0) return;

    printTopIPs(root->right, remaining);

    for (const auto &ip : root->ips) {
        if (remaining <= 0) break;
        std::cout << "IP: " << ip << " - Access: " << root->accessCount << std::endl;
        remaining--;
    }

    printTopIPs(root->left, remaining);
}

void deleteTree(BSTNode *&root) {
    if (!root) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

std::string extractIP(const std::string &line) {
    std::istringstream iss(line);
    std::string datePart, timePart, ipPort;
    iss >> datePart >> datePart >> timePart >> ipPort;

    size_t colonPos = ipPort.find(':');
    if (colonPos != std::string::npos) {
        return ipPort.substr(0, colonPos);
    }
    return "";
}

void main() {
    const std::string path = "../data/sorted-logs.txt";
    std::ifstream infile(path);

    if (!infile) {
        std::cerr << "Failed to access file at " << path << std::endl;
        return;
    }

    std::unordered_map< std::string, int > ipCounts;
    std::string line;

    while (std::getline(infile, line)) {
        if (std::string ip = extractIP(line) ; !ip.empty()) {
            ipCounts[ip]++;
        }
    }

    BSTNode *root = nullptr;
    for (const auto &[ip, count] : ipCounts) {
        root = insert(root, count, ip);
    }

    int top = 5;
    std::cout << "Top" << top << " IPs with more access:\n";
    printTopIPs(root, top);

    deleteTree(root);
}
