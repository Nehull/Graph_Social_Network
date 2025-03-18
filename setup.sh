#!/bin/bash

echo "🔧 Setting up the Graph-Based Social Network Project..."

# Install build tools and Graphviz (Linux)
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    echo "📦 Installing C++ build tools and Graphviz..."
    sudo apt update
    sudo apt install -y build-essential graphviz

# Install build tools and Graphviz (Windows - Git Bash or WSL)
elif [[ "$OSTYPE" == "msys"* || "$OSTYPE" == "win32" ]]; then
    echo "📦 Installing MinGW and Graphviz (Windows)..."
    pacman -S --noconfirm mingw-w64-x86_64-gcc graphviz

else
    echo "❌ Unsupported OS"
    exit 1
fi

# Compile the C++ code
echo "⚙️  Compiling C++ code..."
make

# Install Python dependencies
echo "🐍 Installing Python dependencies..."
pip install -r requirements.txt

echo "✅ Setup completed successfully!"
