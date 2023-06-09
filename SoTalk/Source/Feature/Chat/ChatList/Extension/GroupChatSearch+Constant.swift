//
//  GroupChatSearch+Constant.swift
//  SoTalk
//
//  Created by 양승현 on 2023/05/30.
//

import UIKit

extension GroupChatSearch {
  enum Constant {
    static let cornerRadius = 17.0
    enum Icon {
      static let size = CGSize(width: 14, height: 14)
      static let spacing: UISpacing = .init(leading: 24)
      static let name = "search"
      static let color = UIColor.Palette.primaryHalf
    }
    
    enum TextField {
      static let spacing: UISpacing = .init(leading: 11, trailing: 25)
      static let size = 14.0
      static let textColor = UIColor.Palette.primary
      static let placeholderColor = UIColor.Palette.primaryHalf
    }
  }
}
